# Aveva.Core.Database.Filters

**Assembly:** Aveva.Core.Database.Filters, Version=12.0.0.0, Culture=neutral, PublicKeyToken=17c64733a9775004

**Total types:** 74

---

## Aveva.Core.Database.Filters.ActualTypeFilter
_Extends: TypeFilter_

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(DbElementType type) |
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AndFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| BaseFilter[] | filters |
| BaseFilter | First |
| BaseFilter | Second |

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(BaseFilter filt) |
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Void | **Remove**(BaseFilter filt) |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement element, String& falseMessage) |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeDateTimeFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |
| DbQualifier | Qualifier |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeDbDoubleFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |
| DbQualifier | Qualifier |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeDbDoubleRangeFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeDoubleFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |
| DbQualifier | Qualifier |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeDoubleRangeFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeFalseFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |
| DbQualifier | Qualifier |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeIntFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |
| DbQualifier | Qualifier |

### Methods

| Return | Signature |
|--------|-----------|
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeIntRangeFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |

### Methods

| Return | Signature |
|--------|-----------|
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeLikeFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |

### Methods

| Return | Signature |
|--------|-----------|
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeListFilter
_Extends: BaseFilter_

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Int32 | **CompareAttributeValues**(DbElement ele, DbAttribute testAtt, Object testVal, Boolean& bExist) |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeRangeFilter
_Extends: BaseFilter_

### Methods

| Return | Signature |
|--------|-----------|
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeRefFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |
| DbQualifier | Qualifier |

### Methods

| Return | Signature |
|--------|-----------|
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeStringFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |
| DbQualifier | Qualifier |

### Methods

| Return | Signature |
|--------|-----------|
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeTrueFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |
| DbQualifier | Qualifier |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeUnsetFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbAttribute | Attribute |
| Boolean | Not |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.AttributeValueFilter
_Extends: BaseFilter_

### Methods

| Return | Signature |
|--------|-----------|
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.BaseAttributeFilter

### Methods

| Return | Signature |
|--------|-----------|
| BaseFilter | **GetAttributeFilter**(DbAttribute dbAtt, FilterOperator filterOperator, Object attValue) |

---

## Aveva.Core.Database.Filters.BaseFilter

### Properties

| Type | Name |
|------|------|
| Boolean | ErrorOnValid |
| Interrupt | Interrupt |

### Methods

| Return | Signature |
|--------|-----------|
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| DbElement | **FirstMember**(DbElement element) |
| PdmsMessage | **GetError**() |
| DbElement[] | **Members**(DbElement ele) |
| DbElement | **Next**(DbElement element) |
| Boolean | **op_Equality**(BaseFilter f1, BaseFilter f2) |
| Boolean | **op_Inequality**(BaseFilter f1, BaseFilter f2) |
| DbElement | **Parent**(DbElement element) |
| Boolean | **ScanBelow**(DbElement element) |
| Boolean | **Valid**(DbElement element) |
| Boolean | **Valid**(DbElement element, String& falseMessage) |

---

## Aveva.Core.Database.Filters.BelowFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| BaseFilter | Filter |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.BelowOrAtFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| BaseFilter | Filter |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.BelowOrAtType
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbElementType[] | types |

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(DbElementType[] types) |
| Void | **Add**(DbElementType type) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Void | **Remove**(DbElementType type) |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.BelowType
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbElementType[] | types |

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(DbElementType[] types) |
| Void | **Add**(DbElementType type) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Void | **Remove**(DbElementType type) |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.CatalogueCataFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.CataloguePartWorldFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.CatalogueSpecWorldFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.CatalogueTableWorldFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.CombineType
_Extends: Enum_

---

## Aveva.Core.Database.Filters.CompoundFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| BaseFilter[] | Hides |
| BaseFilter[] | Shows |
| BaseFilter[] | Skips |

### Methods

| Return | Signature |
|--------|-----------|
| Void | **AddHide**(BaseFilter filt) |
| Void | **AddShow**(BaseFilter filt) |
| Void | **AddSkip**(BaseFilter filt) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Void | **RemoveHide**(BaseFilter filt) |
| Void | **RemoveShow**(BaseFilter filt) |
| Void | **RemoveSkip**(BaseFilter filt) |
| Boolean | **ScanBelow**(DbElement ele) |
| Boolean | **TestSkip**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele, String& falseMessage) |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.DbAttributeExtensions

### Methods

| Return | Signature |
|--------|-----------|
| Boolean | **IsExpression**(DbAttribute dbAtt) |

---

## Aveva.Core.Database.Filters.DBElementCollection

### Properties

| Type | Name |
|------|------|
| BaseFilter | Filter |
| Boolean | IncludeRoot |
| Interrupt | Interrupt |

### Methods

| Return | Signature |
|--------|-----------|
| IEnumerator | **GetEnumerator**() |

---

## Aveva.Core.Database.Filters.DBElementEnumerator

### Properties

| Type | Name |
|------|------|
| Int32 | CountSoFar |
| Object | Current |
| Int32 | Scanned |

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Dispose**() |
| Boolean | **MoveNext**() |
| Void | **OutputCount**() |
| Void | **Reset**() |

---

## Aveva.Core.Database.Filters.DbElementListFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| IEnumerable`1 | Elements |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement element) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement element) |

---

## Aveva.Core.Database.Filters.DBElementTypeCollection

### Methods

| Return | Signature |
|--------|-----------|
| Boolean | **Equals**(String x, String y) |
| Int32 | **GetHashCode**(String obj) |
| List`1 | **GetSystemAndUserDefinedElementTypes**() |

---

## Aveva.Core.Database.Filters.DBTypeFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbType | Type |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.DraftAdminFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.DraftFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.ElementTreeNavigator

### Properties

| Type | Name |
|------|------|
| CompoundFilter | Filter |
| DbElement | TopElement |

### Methods

| Return | Signature |
|--------|-----------|
| DbElement[] | **DbWorldMembersInScan**(Db db) |
| DbElement | **FirstMemberInScan**(DbElement startce) |
| Boolean | **HasMember**(DbElement ele, DbElementType eleType) |
| Boolean | **HasMembers**(DbElement ele) |
| DbElement[] | **MembersInScan**(DbElement ele) |
| DbElement | **NextInScan**(DbElement startce) |
| DbElement | **Parent**(DbElement ele) |

---

## Aveva.Core.Database.Filters.EquipmentFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.ExpressionFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| Boolean | ErrorOnValid |
| DbExpression | Expression |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| PdmsMessage | **GetError**() |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.FalseFilter
_Extends: BaseFilter_

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.FieldIntFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbNounField | Field |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.FieldTrueFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbNounField | Field |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.FilterOperator
_Extends: Enum_

---

## Aveva.Core.Database.Filters.FilterOperatorConverter
_Extends: TypeConverter_

### Properties

| Type | Name |
|------|------|
| FilterOperator[] | AllOperators |
| FilterOperator[] | BooleanOperators |
| FilterOperator[] | DateTimeOperators |
| FilterOperator[] | ElementOperators |
| FilterOperator[] | NumberOperators |
| FilterOperator[] | SpaceRelatedOperators |
| FilterOperator[] | StringOperators |

### Methods

| Return | Signature |
|--------|-----------|
| Boolean | **CanConvertFrom**(ITypeDescriptorContext context, Type sourceType) |
| Boolean | **CanConvertTo**(ITypeDescriptorContext context, Type destinationType) |
| Object | **ConvertFrom**(ITypeDescriptorContext context, CultureInfo culture, Object value) |
| Object | **ConvertTo**(ITypeDescriptorContext context, CultureInfo culture, Object value, Type destinationType) |
| FilterOperator | **GetFilterOperator**(String strOp) |
| String | **GetStringOperator**(FilterOperator filterOp) |
| FilterOperator | **GetUpperCaseFilterOperator**(String upperString) |
| Boolean | **IsValid**(ITypeDescriptorContext context, Object value) |

---

## Aveva.Core.Database.Filters.HangerFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.HideBelowFilter
_Extends: TypeFilter_

### Methods

| Return | Signature |
|--------|-----------|
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.HideFilter
_Extends: TypeFilter_

### Methods

| Return | Signature |
|--------|-----------|
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.HullcFilter
_Extends: CompoundFilter_

---

## Aveva.Core.Database.Filters.HullFilter
_Extends: CompoundFilter_

---

## Aveva.Core.Database.Filters.IFilterOperatorConverter

### Properties

| Type | Name |
|------|------|
| FilterOperator[] | AllOperators |
| FilterOperator[] | BooleanOperators |
| FilterOperator[] | DateTimeOperators |
| FilterOperator[] | ElementOperators |
| FilterOperator[] | NumberOperators |
| FilterOperator[] | SpaceRelatedOperators |
| FilterOperator[] | StringOperators |

### Methods

| Return | Signature |
|--------|-----------|
| Boolean | **CanConvertFrom**(ITypeDescriptorContext context, Type sourceType) |
| Boolean | **CanConvertTo**(ITypeDescriptorContext context, Type destinationType) |
| Object | **ConvertFrom**(ITypeDescriptorContext context, CultureInfo culture, Object value) |
| Object | **ConvertTo**(ITypeDescriptorContext context, CultureInfo culture, Object value, Type destinationType) |
| FilterOperator | **GetFilterOperator**(String strOp) |
| String | **GetStringOperator**(FilterOperator filterOp) |
| Boolean | **IsValid**(ITypeDescriptorContext context, Object value) |

---

## Aveva.Core.Database.Filters.InLimitsBoxFilter
_Extends: DbElementListFilter_

### Properties

| Type | Name |
|------|------|
| Boolean | CompletelyWithin |
| DbElementType[] | DbElementTypes |
| LimitsBox | LimitsBox |

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.InvisibleFilter
_Extends: BaseFilter_

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.InVolumeFilter
_Extends: DbElementListFilter_

### Properties

| Type | Name |
|------|------|
| Boolean | CompletelyWithin |
| DbElementType[] | DbElementTypes |
| DbElement | InVolumeOfElement |

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.OnDiagramFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbElement | Diagram |
| Int32 | PageNumber |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement element) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement element) |

---

## Aveva.Core.Database.Filters.OrFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| BaseFilter[] | filters |
| BaseFilter | First |
| BaseFilter | Second |

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(BaseFilter filt) |
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Void | **Remove**(BaseFilter filt) |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.PipingFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.RefmodFilter
_Extends: CompoundFilter_

---

## Aveva.Core.Database.Filters.Res

### Methods

| Return | Signature |
|--------|-----------|
| String | **GetString**(String resourceId, Object[] args) |
| String | **GetString**(String resourceId) |
| String | **GetStringFromResourceSet**(String resourceSet, String resourceId, Object[] args) |
| String | **GetStringFromResourceSet**(String resourceSet, String resourceId) |
| Boolean | **InitialisedOk**(String resourceSet) |

---

## Aveva.Core.Database.Filters.SchematicElectricalFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.SchematicHVACFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.SchematicPipingFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.ShowDescendants
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbElementType[] | types |

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(DbElementType[] types) |
| Void | **Add**(DbElementType type) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Void | **Remove**(DbElementType type) |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.ShowFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbElementType[] | types |

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(DbElementType[] types) |
| Void | **Add**(DbElementType type) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Void | **Remove**(DbElementType type) |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.SkipFilter
_Extends: TypeFilter_

### Methods

| Return | Signature |
|--------|-----------|
| Boolean | **ScanBelow**(DbElement element) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.SpacearrFilter
_Extends: CompoundFilter_

---

## Aveva.Core.Database.Filters.StructuralFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.SystemFilter
_Extends: CompoundFilter_

### Methods

| Return | Signature |
|--------|-----------|
| String | **ToString**() |

---

## Aveva.Core.Database.Filters.TestOperator
_Extends: Enum_

---

## Aveva.Core.Database.Filters.TrueFilter
_Extends: BaseFilter_

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement element) |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.TypeFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| DbElementType[] | types |

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(DbElementType[] types) |
| Void | **Add**(DbElementType actualType) |
| IEnumerator | **AlternativeEnumerator**(Db db, Int32& priority) |
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **Match**(DbElementType typ, Hashtable types) |
| Void | **Remove**(DbElementType type) |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.TypeOrActualTypeFilter
_Extends: TypeFilter_

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(DbElementType type) |
| Object | **Clone**() |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

## Aveva.Core.Database.Filters.UserDefinedTypeGroupFilter
_Extends: BaseFilter_

### Properties

| Type | Name |
|------|------|
| List`1 | TypeExcludes |

### Methods

| Return | Signature |
|--------|-----------|
| Object | **Clone**() |
| Boolean | **Equals**(Object o) |
| Int32 | **GetHashCode**() |
| Boolean | **ScanBelow**(DbElement ele) |
| String | **ToString**() |
| Boolean | **Valid**(DbElement ele) |

---

