#include "pch.h"
#include "AiAvevaInteraction.h"
#include "cstdio"

using namespace std;
using namespace System::Runtime::InteropServices;
using namespace AiAvevaInteraction;

AiAvevaInteractionObj::AiAvevaInteractionObj() {
	AiAvevaInteractionObj::isEnvOpen = false;
}

AiAvevaInteractionObj::~AiAvevaInteractionObj() {}

void AiAvevaInteractionObj::StartVenvPy(System::String^ venv_exe_path) {

	if (AiAvevaInteractionObj::isEnvOpen)
	{
		Console::WriteLine("Python Environment is Already Running.");
		return;
	}

	try
	{
		PyConfig pyConfig;
		PyStatus pyStatus;
		AiAvevaInteractionObj::pyConfig = &pyConfig;
		AiAvevaInteractionObj::pyStatus = &pyStatus;
		pin_ptr<const wchar_t> wch_venv_exe_path = PtrToStringChars(venv_exe_path);

		PyConfig_InitIsolatedConfig(AiAvevaInteractionObj::pyConfig);
		PyConfig_SetString(AiAvevaInteractionObj::pyConfig, &AiAvevaInteractionObj::pyConfig->executable, wch_venv_exe_path);

		// Set home to the directory containing python.exe so Python can find its stdlib (encodings, etc.)
		System::String^ homeDir = System::IO::Path::GetDirectoryName(venv_exe_path);
		pin_ptr<const wchar_t> wch_home = PtrToStringChars(homeDir);
		PyConfig_SetString(AiAvevaInteractionObj::pyConfig, &AiAvevaInteractionObj::pyConfig->home, wch_home);

		AiAvevaInteractionObj::pyStatus = &Py_InitializeFromConfig(AiAvevaInteractionObj::pyConfig);
		if (PyStatus_Exception(*AiAvevaInteractionObj::pyStatus)) {
			goto exception;
		}

		PyConfig_Clear(AiAvevaInteractionObj::pyConfig);

		// Add the directory containing this DLL to sys.path so pyavevae3dext.pyd is found automatically
		System::String^ dllDir = System::IO::Path::GetDirectoryName(
			System::Reflection::Assembly::GetExecutingAssembly()->Location);
		System::String^ sysPathCmd = "import sys; sys.path.insert(0, r'" + dllDir + "')";
		PyRun_SimpleString(typecast::StringToCharP(sysPathCmd));
		Console::WriteLine("Added to sys.path: " + dllDir);

		Console::WriteLine("Python Virtual Environment Started Successfuly.");
		AiAvevaInteractionObj::isEnvOpen = true;
		return;
	exception:
		PyConfig_Clear(AiAvevaInteractionObj::pyConfig);
		if (PyStatus_IsExit(*AiAvevaInteractionObj::pyStatus))
		{
			Console::WriteLine("ExitCode :" + AiAvevaInteractionObj::pyStatus->exitcode);
		}
		Console::WriteLine("Exception in StartVenvPy");
	}
	catch (System::Exception^ ex)
	{
		Console::WriteLine("Managed exception: " + ex->Message);
	}
	catch (...)
	{
		Console::WriteLine("exception something went wrong");
	}
}

void AiAvevaInteractionObj::StartSysPy() {

	if ( AiAvevaInteractionObj::isEnvOpen )
	{
		Console::WriteLine("Python Environment is Already Running.");
		return;
	}

	try
	{
		Py_Initialize();
		if (!Py_IsInitialized()) {
			Console::WriteLine("Python initialization failed!");
		}
		else
		{
			AiAvevaInteractionObj::isEnvOpen = true;

			// Add the directory containing this DLL to sys.path so pyavevae3dext.pyd is found automatically
			System::String^ dllDir = System::IO::Path::GetDirectoryName(
				System::Reflection::Assembly::GetExecutingAssembly()->Location);
			System::String^ sysPathCmd = "import sys; sys.path.insert(0, r'" + dllDir + "')";
			PyRun_SimpleString(typecast::StringToCharP(sysPathCmd));

			Console::WriteLine("System Leval Python initialized.");
		}
	}
	catch (System::Exception^ ex)
	{
		Console::WriteLine("Managed exception: " + ex->Message);
	}
	catch (...)
	{
		Console::WriteLine("exception something went wrong");
	}
}

void AiAvevaInteractionObj::RunPyFile(System::String^ filePath) {
	if (!AiAvevaInteractionObj::isEnvOpen)
	{
		Console::WriteLine("Python Environment is not running to run the file " + filePath);
		return;
	}

	try
	{
		AiAvevaInteractionObj::RunPythonFile(typecast::StringToCharP(filePath));
	}
	catch (System::Exception^ ex)
	{
		Console::WriteLine("Managed exception: " + ex->Message);
	}
	catch (...)
	{
		Console::WriteLine("Something went wrong in RunPyFileInVenv");
	}
}

void AiAvevaInteractionObj::RunPyCode(System::String^ PythonCode) {
	if (!AiAvevaInteractionObj::isEnvOpen)
	{
		Console::WriteLine("Python Environment is not running to run the code " + PythonCode);
		return;
	}

	try
	{
		PyObject* sys = PyImport_ImportModule("sys");
		PyObject* stringIO = PyImport_ImportModule("io");
		PyObject* pyOutput = PyObject_CallMethod(stringIO, "StringIO", nullptr);

		PyObject_SetAttrString(sys, "stdout", pyOutput);
		PyObject_SetAttrString(sys, "stderr", pyOutput);

		if (PyRun_SimpleString(typecast::StringToCharP(PythonCode)) != 0) {
			PyErr_Print();
		}

		PyObject* output = PyObject_CallMethod(pyOutput, "getvalue", nullptr);
		const char* outputStr = PyUnicode_AsUTF8(output);
		Py_XDECREF(output);
		Py_XDECREF(pyOutput);
		Py_XDECREF(sys);
		Py_XDECREF(stringIO);
		Console::WriteLine(typecast::CharPToString(outputStr));
	}
	catch (System::Exception^ ex)
	{
		Console::WriteLine("Managed exception: " + ex->Message);
	}
	catch (...)
	{
		Console::WriteLine("Something went wrong in RunPyCodeInVenv");
	}
}

void AiAvevaInteractionObj::StopPy() {
	if (!AiAvevaInteractionObj::isEnvOpen)
	{
		Console::WriteLine("Python Environment is not Running.");
		return;
	}

	try
	{
		Py_Finalize();
		AiAvevaInteractionObj::isEnvOpen = false;
		Console::WriteLine("Python Environment is Closed.");
	}
	catch (System::Exception^ ex)
	{
		Console::WriteLine("Managed exception: " + ex->Message);
	}
	catch (...)
	{
		Console::WriteLine("Something went wrong in StopVenvPy");
	}
}

void  AiAvevaInteractionObj::Assign(AiAvevaInteractionObj that) {}

void  AiAvevaInteractionObj::RunPythonFile(const char* filePath) {

	PyObject* obj = Py_BuildValue("s", filePath);
	FILE* fd = _Py_fopen_obj(obj, "r");

	PyObject* sys = PyImport_ImportModule("sys");
	PyObject* stringIO = PyImport_ImportModule("io");
	PyObject* pyOutput = PyObject_CallMethod(stringIO, "StringIO", nullptr);

	PyObject_SetAttrString(sys, "stdout", pyOutput);
	PyObject_SetAttrString(sys, "stderr", pyOutput);

	if (PyRun_SimpleFile(fd, filePath) != 0) {
		PyErr_Print();
	}

	PyObject* output = PyObject_CallMethod(pyOutput, "getvalue", nullptr);
	const char* outputStr = PyUnicode_AsUTF8(output);
	Py_XDECREF(output);
	Py_XDECREF(pyOutput);
	Py_XDECREF(sys);
	Py_XDECREF(stringIO);
	Console::WriteLine(typecast::CharPToString(outputStr));
}