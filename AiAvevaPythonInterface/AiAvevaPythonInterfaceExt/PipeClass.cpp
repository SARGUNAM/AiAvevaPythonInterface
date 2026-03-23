#include "AvevaWraperClassDefinations.h"

using namespace Aveva::Core::Database;
using namespace Aveva::Core::Utilities::CommandLine;
using namespace System;

array<System::String^>^ PipeClass::getAllPipes(System::String^ scope) {
    ACDF::DBElementCollection^ coll = gcnew ACDF::DBElementCollection(
        DbElement::GetElement(scope),
        gcnew ACDF::TypeFilter(DbElementType::GetElementType("PIPE")));
    return typecast::GetArrayFromCollection(coll);
}

array<System::String^>^ PipeClass::getAllPipesFromProject() {
    ACDF::DBElementCollection^ coll = gcnew ACDF::DBElementCollection(
        DbType::Design,
        gcnew ACDF::TypeFilter(DbElementType::GetElementType("PIPE")));
    return typecast::GetArrayFromCollection(coll);
}

System::String^ PipeClass::getAttribute(System::String^ pipeName, System::String^ attName) {
    try
    {
        DbElement^ elm = DbElement::GetElement(pipeName);
        DbAttribute^ att = DbAttribute::GetDbAttribute(attName);
        System::Object^ val = elm->GetAttribute(att);
        if (val == nullptr) return "";
        return val->ToString();
    }
    catch (System::Exception^)
    {
        // Dimension attributes (e.g. BORE, HEIGHT, WIDTH) cannot be read as generic Object.
        // Fall back to PML expression: !!_AIATT = ##elementName##.ATTNAME
        try
        {
            String^ pmlExpr = "!!_AIATT = ##" + pipeName + "##." + attName;
            Command^ cmd = Command::CreateCommand(pmlExpr);
            cmd->Run();
            Command^ readCmd = Command::CreateCommand("");
            double realVal = readCmd->GetPMLVariableReal("!!_AIATT");
            return System::Convert::ToString(realVal);
        }
        catch (System::Exception^ ex2)
        {
            Console::WriteLine("getAttribute error: " + ex2->Message);
            return "";
        }
    }
}

array<System::String^>^ PipeClass::getBranches(System::String^ pipeName) {
    ACDF::DBElementCollection^ coll = gcnew ACDF::DBElementCollection(
        DbElement::GetElement(pipeName),
        gcnew ACDF::TypeFilter(DbElementType::GetElementType("BRAN")));
    return typecast::GetArrayFromCollection(coll);
}

array<System::String^>^ PipeClass::getComponents(System::String^ branchName) {
    ACDF::DBElementCollection^ coll = gcnew ACDF::DBElementCollection(
        DbElement::GetElement(branchName));
    return typecast::GetArrayFromCollection(coll);
}
