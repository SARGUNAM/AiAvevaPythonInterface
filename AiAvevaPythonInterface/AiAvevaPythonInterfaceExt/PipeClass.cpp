#include "AvevaWraperClassDefinations.h"

using namespace Aveva::Core::Database;
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

System::String^ PipeClass::getAttribute(System::String^ elementName, System::String^ attName) {
    try
    {
        DbElement^ elm = DbElement::GetElement(elementName);
        DbAttribute^ att = DbAttribute::GetDbAttribute(attName);
        if (!elm->IsAttributeValid(att)) return "";
        return elm->GetAsString(att);
    }
    catch (System::Exception^ ex)
    {
        Console::WriteLine("getAttribute error: " + ex->Message);
        return "";
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
