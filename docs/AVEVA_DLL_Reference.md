# AVEVA .NET DLL Reference

All DLLs from `N:\MswR400Develop\Net\ue4_DLL\` (v12.0.0.0).
Local copy: `C:\Aibelprogs\AvevaDLL\ue4_DLL\`

---

## Table of Contents

1. [Aveva.Core.dll](#1-avevacorédll) — Application lifecycle, licensing, environment
2. [Aveva.Core.Database.dll](#2-avevacoreéatabasedll) — Core DB access: elements, attributes, sessions
3. [Aveva.Core.Database.Filters.dll](#3-avevacoreéatabaseéiltersdll) — Element collection filtering
4. [Aveva.Core.Database.Implementation.dll](#4-avevacoreéatabaseéimplementationdll) — Concrete DB service implementations
5. [Aveva.Core.DatabaseInternal.dll](#5-avevacoreéatabaseinternaldll) — Low-level DAB/transaction/naming services
6. [Aveva.Core.Commands.dll](#6-avevacoreéommandsdll) — UI commands, PMLNetCommand bridge
7. [Aveva.Core.Utilities.dll](#7-avevacoreéutilitiesdll) — PML command execution, messaging, modules, undo

---

## 1. Aveva.Core.dll

**9 types** — Application lifecycle and version info.

### `PdmsApplication` — Application singleton

| Method | Description |
|--------|-------------|
| `Start(bool isGraphics, int moduleNumber, string moduleName, ...)` | Start the PDMS application |
| `Close()` / `Exit(String message)` / `Finish()` | Shut down the application |
| `InitialiseCoreModule(bool commsfile)` | Initialise core module |
| `InitialiseAdmin(bool)` / `InitialiseConfiguration(bool)` / `InitialiseLexicon(bool)` | Initialise subsystems |
| `InitialiseUomData()` | Load unit-of-measure data |
| `ExpandPdmsEnvironmentVariables(String expression)` | Expand `%VAR%` style env vars |
| `GetPdmsEnvironmentVariables(String expression)` | Get matching env var names |
| `SetPdmsEnvironmentVariable(String name, String value)` | Set an env var |
| `GetExistingPdmsFilePath(String filePath)` | Resolve a file path using PDMS search paths |
| `GetPdmsFilePaths(String filePath)` | Get all matching PDMS file paths |
| `ProjectList(bool isPathRequired)` | Get available projects as `Hashtable` |
| `licFeatureCheckOut(String feature, int checkSum)` | Checkout a licence feature |
| `licFeatureCheckIn(String feature, int checkSum)` | Return a licence feature |
| `licFeatureExists(String feature, int checkSum)` | Test if licence feature exists |
| `StartEventLoop()` | Start the application event loop |
| `OpenProjectAfterModuleSwitch()` | Re-open project after module switch |
| **Events**: `BeforeFinished`, `Finished`, `FatalFinished`, `StartupFailure` | Application lifecycle events |

### `PdmsVersion` — Product version info

| Method | Description |
|--------|-------------|
| `GetVersion()` | Full version string |
| `GetName()` | Product name |
| `GetCompanyName()` / `GetCopyright()` | Branding strings |
| `GetModuleVersion(ModuleType)` | Version for a specific module |
| `GetBundleVersion()` | Bundle version string |
| `GetShortBanner()` | Short banner string |
| `SetProductInfo(...)` | Set version/build/date/copyright info |
| `AddSubsystemInfo(String subsystem, String version, ...)` | Register subsystem version |

### Enums
- `ModuleType` — identifies application modules
- `PdmsApplication.CoordinateSystem` — coordinate system type

---

## 2. Aveva.Core.Database.dll

**203 types** — The primary API for reading and writing AVEVA plant database elements.

### `DbElement` — Core plant element

| Method | Description |
|--------|-------------|
| `DbElement.GetElement(String name)` | **Static** — look up element by name |
| `DbElement.GetElement(DbRef ref)` | Look up by DB reference |
| `GetAttribute(DbAttribute)` | Get any attribute value as `Object` (throws for Distance types) |
| `GetAsString(DbAttribute)` | Get any attribute as string — **works for ALL types including Distance/BORE** |
| `GetDbDouble(DbAttribute)` | Get a dimension/distance attribute as `DbDouble` |
| `SetAttribute(DbAttribute, Object)` | Set an attribute value |
| `Members()` | Get child elements |
| `Owner()` | Get parent element |
| `Next()` / `Previous()` | Navigate siblings |
| `IsValid` | Is the element reference valid? |
| `DbType` / `ElementType` | The element's DB type and element type |
| `Name` / `FullName` | Element name properties |

### `DbAttribute` — Attribute descriptor

| Method | Description |
|--------|-------------|
| `DbAttribute.GetDbAttribute(String name)` | **Static** — look up attribute by name (e.g. `"BORE"`) |
| `Name` | Attribute name |
| `DbType` | Attribute data type |

### `CurrentElement` — CE navigation

| Method/Property | Description |
|-----------------|-------------|
| `Element` (get/set) | Get or set the current element |
| **Event**: `CurrentElementChanged` | Fires when CE changes |

### `DatabaseService` — Project/MDB lifecycle

| Method | Description |
|--------|-------------|
| `OpenProject(String name, String username, String password, ...)` | Open a project, returns `Project` |
| `IsPasswordProtected(String projName)` | Check if project needs password |
| `IsPrimarySystemDb(String projName)` | Check if it is the system DB |
| **Events**: `MDBOpened`, `MDBClosed`, `MDBClosing`, `Changes`, `Claim`, `Release`, `PreUndo`/`PostUndo`, `PreRedo`/`PostRedo`, `PreGetWork`/`PostGetWork`, `PostOpenProject` | Database lifecycle hooks |

### `AutoName` — Auto-naming service

| Method | Description |
|--------|-------------|
| `nameElement(DbElement)` | Auto-name an element |
| `Enabled` | Is auto-naming enabled? |
| `IsAvailable` | Is auto-naming available? |

### Key supporting types

| Type | Purpose |
|------|---------|
| `DbRef` | Persistent reference to a DB element |
| `DbDouble` | Dimension value with units |
| `DbExpression` | PML expression |
| `DbBlob` | Binary attribute blob |
| `DbElementType` | Element type descriptor |
| `DbType` | DB data type descriptor |
| `DbAttribute` | Attribute descriptor |
| `DbNounField` | Noun field descriptor |
| `DbSession` | Database session |
| `Project` | Opened project |
| `Db` | Database handle |
| `LimitsBox` | 3D bounding box |
| `DBElementCollection` (via Filters) | Iterable filtered element set |

---

## 3. Aveva.Core.Database.Filters.dll

**74 types** — Filter elements in `DBElementCollection` queries.

### `DBElementCollection` — Filterable element iterator

| Property | Description |
|----------|-------------|
| `Filter` (get/set) | The `BaseFilter` to apply |
| `IncludeRoot` | Include root element in results |
| `Interrupt` | Cancellation token |
| `GetEnumerator()` | Iterate matching elements |

### `BaseFilter` — Filter base class (all filters inherit this)

| Method | Description |
|--------|-------------|
| `Valid(DbElement)` | Test if element matches |
| `ScanBelow(DbElement)` | Should the scan descend into this element's children? |
| `FirstMember(DbElement)` / `Next(DbElement)` | Manual iteration |
| `Members(DbElement)` | Get all matching members |
| `AlternativeEnumerator(Db, int&)` | Index-optimised enumeration |

### Type / structure filters

| Filter | Description |
|--------|-------------|
| `TypeFilter` | Match by `DbElementType` (add multiple) |
| `ActualTypeFilter` | Match by actual (leaf) type |
| `TypeOrActualTypeFilter` | Match type or actual type |
| `ShowFilter` | Include only listed types |
| `HideFilter` | Exclude listed types |
| `SkipFilter` | Skip (don't descend) listed types |
| `BelowType` | Only scan below listed types |
| `BelowOrAtType` | Scan at and below listed types |
| `HideBelowFilter` | Hide elements below a type |
| `ShowDescendants` | Show descendants of listed types |
| `DBTypeFilter` | Filter by `DbType` |
| `UserDefinedTypeGroupFilter` | Filter by user-defined type group |

### Attribute value filters

| Filter | Description |
|--------|-------------|
| `AttributeStringFilter` | String attribute == value |
| `AttributeLikeFilter` | String attribute LIKE pattern |
| `AttributeIntFilter` | Int attribute comparison |
| `AttributeIntRangeFilter` | Int in range |
| `AttributeDoubleFilter` | Double comparison |
| `AttributeDoubleRangeFilter` | Double in range |
| `AttributeDbDoubleFilter` | `DbDouble` (dimension) comparison |
| `AttributeDbDoubleRangeFilter` | `DbDouble` in range |
| `AttributeDateTimeFilter` | DateTime comparison |
| `AttributeRefFilter` | Element reference comparison |
| `AttributeTrueFilter` | Boolean attribute is true |
| `AttributeFalseFilter` | Boolean attribute is false |
| `AttributeUnsetFilter` | Attribute is unset (null) |
| `AttributeValueFilter` | Generic value comparison |
| `AttributeListFilter` | Attribute matches a list of values |
| `AttributeRangeFilter` | Generic range |
| `ExpressionFilter` | Filter by PML `DbExpression` |
| `BaseAttributeFilter.GetAttributeFilter(DbAttribute, FilterOperator, Object)` | **Factory** — create any attribute filter from operator enum |

### Logical combinators

| Filter | Description |
|--------|-------------|
| `AndFilter` | Both sub-filters must match |
| `OrFilter` | Either sub-filter matches |
| `TrueFilter` | Always matches |
| `FalseFilter` | Never matches |
| `BelowFilter` | Delegates scan-below to inner filter |
| `BelowOrAtFilter` | Delegates scan-below including root |
| `CompoundFilter` | Has Shows, Hides, Skips lists |

### Spatial filters

| Filter | Description |
|--------|-------------|
| `InLimitsBoxFilter` | Elements within a 3D bounding box |
| `InVolumeFilter` | Elements inside the volume of a reference element |
| `OnDiagramFilter` | Elements placed on a specific diagram/page |

### Pre-built compound filters (discipline shortcuts)

| Filter | Covers |
|--------|--------|
| `PipingFilter` | All piping elements |
| `EquipmentFilter` | All equipment |
| `StructuralFilter` | All structural |
| `SystemFilter` | System elements |
| `HangerFilter` | Hangers |
| `SchematicPipingFilter` | Schematic piping |
| `SchematicElectricalFilter` | Schematic electrical |
| `SchematicHVACFilter` | Schematic HVAC |
| `CatalogueCataFilter` | Catalogue CATA |
| `CataloguePartWorldFilter` | Catalogue parts |
| `CatalogueSpecWorldFilter` | Catalogue specs |
| `CatalogueTableWorldFilter` | Catalogue tables |
| `DraftFilter` / `DraftAdminFilter` | Drafting |

### `FilterOperator` enum values (for `BaseAttributeFilter.GetAttributeFilter`)

`EqualTo`, `NotEqualTo`, `LessThan`, `LessThanOrEqualTo`, `GreaterThan`, `GreaterThanOrEqualTo`, `Like`, `NotLike`, `IsSet`, `IsNotSet`, + spatial operators

### `ElementTreeNavigator` — Walk the element tree with a filter

| Method | Description |
|--------|-------------|
| `FirstMemberInScan(DbElement)` | First matching child |
| `NextInScan(DbElement)` | Next matching element |
| `MembersInScan(DbElement)` | All matching children |
| `HasMembers(DbElement, DbElementType)` | Does element have matching children? |
| `DbWorldMembersInScan(Db)` | All matching elements in DB world |
| `TopElement` / `Filter` | Configure root and filter |

---

## 4. Aveva.Core.Database.Implementation.dll

**70 types** — Concrete implementations of the abstract DB services. Typically not used directly; interact via `Aveva.Core.Database` interfaces.

### Key concrete implementations

| Class | Implements | Notes |
|-------|-----------|-------|
| `DatabaseServiceImpl` | `DatabaseService` | Concrete DB service; call `Init()` to start |
| `CurrentElementImpl` | `CurrentElement` | Concrete CE; call `Init()` |
| `DatalListingImpl` | `DatalListing` | DATAL listing/export tool |

### `DatalListingImpl` — DATAL import/export

| Property | Description |
|----------|-------------|
| `Elements` | Elements to list |
| `fileName` | Output file path |
| `screen` | Output to screen |
| `brief` / `changes` / `comments` / `index` | Listing options |
| `nouda` / `oldformat` / `sameref` | Format options |
| `only` | Restrict output |
| `pass` / `session` / `tab` | Session options |
| `ReplaceInTarget` / `LocateParentInTarget` | Import options |

| Method | Description |
|--------|-------------|
| `Initialise()` | Prepare listing |
| `OutputListing()` | Generate output |
| `inputBegin()` / `inputEnd(DbElement[])` / `inputAbort()` | Import control |
| `ShowOptionsForm()` | Show options UI |

### Other implementation classes (internal service impls)
`SessionImpl`, `ProjectImpl`, `DbImpl`, `DbElementImpl`, `DbAttributeImpl`, `DbTypeImpl`, `DbElementTypeImpl`, `DbRefImpl`, `DbDoubleImpl`, `DbExpressionImpl`, `AutoNameImpl`, `DbNameSequenceImpl`, `DbSessionImpl`, `DbTransactionImpl`, `DbCommunicationsImpl`, `DbDabUtilsImpl` — all are internal implementations of DB abstractions; use their abstract counterparts from `Aveva.Core.Database`.

---

## 5. Aveva.Core.DatabaseInternal.dll

**8 types** — Low-level singleton services for DAB operations, transactions, notifications, and name sequences.

### `DbTransaction` — Wrap DB writes for undo/redo

| Method | Description |
|--------|-------------|
| `DbTransaction.GetDbTransaction()` | **Static singleton** |
| `StartTransaction()` | Begin a transaction |
| `CommitTransaction()` | Commit changes |
| `AbortTransaction()` | Roll back |

> Always wrap attribute writes in `StartTransaction` / `CommitTransaction`.

### `DbDabUtils` — Low-level typed attribute setter

| Method | Description |
|--------|-------------|
| `DbDabUtils.GetDbDabUtils()` | **Static singleton** |
| `SetDabAttribute(DbElement, DbAttribute, String, PdmsMessage&)` | Set string attribute |
| `SetDabAttribute(DbElement, DbAttribute, Double, PdmsMessage&)` | Set double |
| `SetDabAttribute(DbElement, DbAttribute, int, PdmsMessage&)` | Set int |
| `SetDabAttribute(DbElement, DbAttribute, Boolean, PdmsMessage&)` | Set bool |
| `SetDabAttribute(DbElement, DbAttribute, DbDouble, PdmsMessage&)` | Set dimension value |
| `SetDabAttribute(DbElement, DbAttribute, DbElement, PdmsMessage&)` | Set element reference |
| `SetDabAttribute(DbElement, DbAttribute, DbExpression, PdmsMessage&)` | Set expression |
| `SetDabAttribute(DbElement, DbAttribute, String[], PdmsMessage&)` | Set string array |
| `SetDabAttribute(DbElement, DbAttribute, DbBlob&, PdmsMessage&)` | Set binary blob |
| `GetPrimarySessionFlag(DbSession, bool&, PdmsMessage&)` | Get session primary flag |
| `SetPrimarySessionFlag(DbSession, bool, PdmsMessage&)` | Set session primary flag |

### `DbNameSequence` — Auto-numbering sequences

| Method | Description |
|--------|-------------|
| `DbNameSequence.GetDbNameSequence(String)` | **Static** — get a named sequence |
| `Next()` | Get next name in sequence |
| `GetCurrent()` / `GetStart()` / `GetStep()` / `GetMax()` | Sequence state |
| `SetCurrent(int)` / `SetStart(int)` / `SetStep(int)` / `SetMax(int)` | Configure sequence |
| `Create()` / `Remove()` / `Exist()` / `ReStart()` | Lifecycle |
| `IsWraparound()` / `SetWraparound()` / `SetNoWraparound()` | Wrap behaviour |
| `GetCounters(...)` / `CheckCountersAvailability(...)` | Bulk counter reservation |
| `ReleaseCounter(int[])` | Return unused counters |

### `DbCommunications` — Communications DB

| Method | Description |
|--------|-------------|
| `DbCommunications.GetDbCommunications()` | **Static singleton** |
| `CreateProject(String projname, String username, String password, ...)` | Create a new project |
| `expunge(DbElement)` / `Expunge(DbElement, String reason, bool force)` | Delete element permanently |
| `Refresh()` | Refresh comms DB |
| `CommsDB` | The communications `Db` handle |
| `CurrUserLoginName` / `CurrUserIdentifer` | Current user info |

### `DbMiscellaneous` — Notifications and subscriptions

| Method | Description |
|--------|-------------|
| `DbMiscellaneous.GetDbMiscellaneous()` | **Static singleton** |
| `StoreNotification(...)` | Store a notification message |
| `GetNotifications(String projId, ...)` | Retrieve notifications |
| `DeleteNotification(DbElement)` | Delete a notification |
| `StoreSubscription(...)` | Store a subscription |
| `GetSubscriptions(String projId, ...)` | Retrieve subscriptions |
| `DeleteSubscriptions(...)` | Delete subscriptions |
| `GetWork()` | Get pending work items |

---

## 6. Aveva.Core.Commands.dll

**33 types** — UI commands and the PML↔.NET command bridge.

### `PMLNetCommand` — **Bridge between PML and .NET**

| Method | Description |
|--------|-------------|
| `Execute(String arg)` | Execute with single PML string arg |
| `Execute(ArrayList args)` | Execute with list of args |
| `Execute()` | Execute with no args |
| `GetString()` / `SetString(String)` | Exchange string data with PML |
| `GetDouble()` / `SetDouble(Double)` | Exchange numeric data |
| `GetBool()` / `SetBool(Boolean)` | Exchange boolean data |
| `GetChecked()` / `SetChecked(Boolean)` | Checkbox/toggle state |
| `GetEnabled()` / `SetEnabled(Boolean)` | Enable/disable button |
| `GetVisible()` / `SetVisible(Boolean)` | Show/hide button |
| `GetDescription()` / `SetDescription(String)` | Tooltip text |
| `GetSelectedIndex()` / `SetSelectedIndex(Double)` | Dropdown selection |
| `GetRunInBackground()` / `SetRunInBackground(Boolean)` | Async execution |
| `GetExecuteOnChecked()` / `SetExecuteOnChecked(Boolean)` | Fire on toggle |
| `AddRefreshFilters(Hashtable)` | Register DB change refresh triggers |
| `Refresh(String what, String how, String id)` | Manual refresh |
| `Assign(PMLNetCommand)` | Copy state |
| `Select()` | Programmatically select |
| **Events**: `PMLNetCommandExecute`, `PMLNetCommandGetState`, `PMLNetCommandIsValid`, `PMLNetCommandList`, `PMLNetCommandRefresh` | PML lifecycle hooks |

### `PMLNetCommandManager` — Registry for PML.NET commands

| Method | Description |
|--------|-------------|
| `AddPMLCommand(PMLNetCommand)` | Register a command |
| `RemovePMLCommand(String key)` | Unregister by key |
| `Command(String key)` | Look up a registered command |
| `ExecuteCommand(String)` / `ExecuteCommand(String, Hashtable args)` | Fire by key |
| `EnableCommand(String, bool)` | Enable/disable by key |
| `CheckCommand(String, bool)` | Check/uncheck by key |
| `ShowCommand(String, bool)` | Show/hide by key |
| `RefreshAll(String, String, String)` | Refresh all commands |
| `Initialise()` / `LoadUI()` / `LoadResource(String)` / `Update()` | Lifecycle |
| `SetApplicationContext(String)` | Set app context |

### `Commands` — Utility

| Method | Description |
|--------|-------------|
| `Commands.Load()` | Load all registered commands |
| `Commands.GetElementTypesList(DbElement, DbType, bool sort)` | Get element types list |

### UI/DB Commands — all extend `Command`

| Class | Action |
|-------|--------|
| `CECommand` | Navigate to Current Element |
| `AttributesCommand` | Open attributes editor |
| `CreateCommand` | Create element (`List` = available types) |
| `DeleteCommand` | Delete element |
| `DeleteMembersCommand` | Delete collection members |
| `EditMembersCommand` | Edit collection members |
| `RenameCommand` | Rename element |
| `SelectEntityCommand` | Select entity in model |
| `OpenSheetCommand` | Open sheet/form; `OpenCE(moduleName)` |
| `OpenSheetReadOnlyCopyCommand` | Open sheet read-only |
| `NavigateToAssociatedElementCommand` | Navigate to linked element |
| `NavigateToAssociatedElementListCommand` | Navigate from list |
| `PlotCommand` | Plot/print |
| `PurgeCommand` | Purge element |
| `DraftAddToLinkDocCommand` | Add to linked doc |
| `DraftRenameCommand` | Rename in drafting |
| `SpoolerRenameCommand` | Rename spool |
| `HelpCommand` | Open help |
| `ClearCanvasCommand` | Clear 3D canvas |
| `ManageRamDiskCommand` | RAM disk management |
| `ResetWindowLayoutCommand` | Reset UI layout |
| `ShowSectionPlanesCommand` | Toggle section planes |
| `NewMenuCommand` | "New" menu action |

### `IBatchUpdateCommand` interface
Subscribe to `StartBatchUpdate` / `EndBatchUpdate` events to suppress intermediate refreshes during bulk operations.

### `DisplayElement` — Name/description pair
Used in `List` properties on commands like `CreateCommand`. Properties: `Name`, `Description`.

### `NavigateToAssociatedElementCommand.AssociationType` enum
Values: `Linked`, `MatchedByName`

---

## 7. Aveva.Core.Utilities.dll

**38 types** — PML command execution, messaging, modules, undo, tracing, units.

### `CommandLine.Command` — **Execute PML from .NET**

| Method | Description |
|--------|-------------|
| `Command.CreateCommand(String)` | **Static factory** — create from PML string |
| `Run()` | Execute, returns `bool` success |
| `RunInCurrentScope()` / `RunInPdms()` / `RunInCurrentScopeInPdms()` | Execution context variants |
| `Queue()` | Queue for deferred execution |
| `GetPMLVariableString(String name)` | Read PML string variable |
| `GetPMLVariableReal(String name)` | Read PML real/double variable |
| `GetPMLVariableBoolean(String name)` | Read PML boolean variable |
| `GetStringArrayFromPML(String arrayName)` | Read PML array as `String[]` |
| `GetDoubleFromPML(String)` / `GetIntFromPML(String)` / `GetBoolFromPML(String)` | Typed PML variable reads |
| `GetStringFromPML(String, String&, PdmsMessage&)` | Read string with error output |
| `RunPMLCommand(String)` | Run arbitrary PML string |
| `RunPMLCommandInPDMS(String)` | Run PML in PDMS context |
| `FormRefresh()` | Refresh active PML form |
| `GraphicsUpdate()` | Trigger 3D graphics refresh |
| `Update()` / `UpdateOn(bool)` | Toggle UI updates |
| `EventsOn(bool)` | Toggle PML event processing |
| `OutputAndClearError()` | Print and clear pending error |
| `ReadPMLIndex()` | Re-index PML macros |
| **Properties**: `CommandString`, `Result`, `Error`, `Enabled` | Command state |
| **Event**: `ReturnHandler` | Fires when command returns |

> **Typical usage pattern (C++/CLI):**
> ```cpp
> Command^ cmd = Command::CreateCommand("!!_AIATT = ##PIPE/101##.BORE");
> cmd->Run();
> double bore = cmd->GetPMLVariableReal("!!_AIATT");
> ```

### `Messaging.PdmsMessage` — AVEVA error/message object

| Method | Description |
|--------|-------------|
| `PdmsMessage.CreateMessage(int module, int messagenum)` | Static factory |
| `MessageText()` | Get the formatted message string |
| `GetText(int pos)` / `GetDouble(int)` / `GetInt(int)` / `GetName(int)` | Get typed parameters |
| `SetText(int, Object)` / `SetDouble(int, Double)` / `SetInt(int, int)` | Set parameters |
| `GetElement(int)` / `SetElement(int, IMessage)` | Element ref params |
| `Output()` / `OutputError()` | Print to AVEVA output window |
| `GetLastError()` | Get last error |
| `EmbedMessage(PdmsMessage)` / `RetrieveEmbeddedMessages()` | Nest/retrieve messages |
| `FlushPmlErrors()` / `ResetErrorOccurred()` / `Reset()` | Clear error state |
| **Properties**: `MessageNumber`, `ModuleNumber` | Message identity |

### `Messaging.PdmsException` — Wraps `PdmsMessage` as exception

| Method | Description |
|--------|-------------|
| `PdmsException.CreateException(PdmsMessage)` | Static factory |
| `Output()` | Print exception to output window |
| **Property**: `Error` | The wrapped `PdmsMessage` |

### `Messaging.PdmsOutput` — Structured output messages

| Method | Description |
|--------|-------------|
| `PdmsOutput.CreateOutput(type, description, details, category)` | Static factory |
| `Send()` / `SendAll(PdmsOutput[])` | Send to output listeners |
| **Properties**: `Type`, `Description`, `Details`, `Category`, `Date` | |

### `Messaging.PdmsOutputEvents` — Subscribe to AVEVA output stream

| Method | Description |
|--------|-------------|
| `AddOutputListener(OutputListener)` | Subscribe to output messages |
| `AddUpdateListener(UpdateListener)` | Subscribe to update events |
| `RemoveOutputListener(...)` / `RemoveUpdateListener(...)` | Unsubscribe |

### `ModuleInfo.ModuleManager` — Current module and product state

| Property | Description |
|----------|-------------|
| `CurrentModule` | Active `Module` (get/set) |
| `CurrentProductName` / `CurrentProductVersion` | Product strings |
| `IsCurrentProductUE` | Running Unified Engineering? |
| `IsCurrentProductE3DUEConnected` | UE connected to E3D? |
| `IntegratedMode` | Integrated mode active? |
| `HaveFullDraw` | Full draw licence? |
| `DrawInModelEnabled` | Draw-in-model active? |
| `UsingDrawingEngine` | Using new drawing engine? |

| Method | Description |
|--------|-------------|
| `Find(String name)` / `Find(int number)` | Find module |
| `ProductModules()` | All modules in current product |
| `IsNextModuleLegal(Module)` | Can switch to this module? |
| `CoreModule()` | Is a core module active? |

### `ModuleInfo.Module` — Module descriptor
Properties: `Name`, `Number`, `Description`, `ExeName`, `IsEntryPoint`, `IsSwitchable`, `IsRestorable`, `IsRestricted`

### `Tracing.PdmsTrace` — Debug tracing

| Method | Description |
|--------|-------------|
| `Trace(String)` / `TraceLine(String)` | Write to trace log |
| `OutputLine(String)` | Write to output window |
| `GetTraceback(bool)` | Get call stack |
| `StartCPUTrace()` / `StopCPUTrace(bool)` | CPU profiling |
| `GetTraceFlag(TraceNumber)` / `SetTraceFlag(TraceNumber, int)` | Trace flags |
| `Flush()` | Flush trace buffer |
| **Properties**: `Enabled`, `TraceLog` (path), `CPUTraceStarted` | |

### `Undo.UndoTransaction` — Bracket DB changes for undo

| Method | Description |
|--------|-------------|
| `UndoTransaction.GetUndoTransaction()` | **Static singleton** |
| `StartTransaction(String description)` | Begin undo block |
| `EndTransaction()` | Commit block |
| `AbortTransaction()` | Roll back |
| `PerformUndo()` / `PerformUndo(String mark)` | Undo |
| `PerformRedo()` | Redo |
| `UndoAvailable()` / `RedoAvailable()` | Check availability |

> **Always wrap DB writes:**
> ```cpp
> UndoTransaction^ undo = UndoTransaction::GetUndoTransaction();
> undo->StartTransaction("Set BORE");
> // ... modify element ...
> undo->EndTransaction();
> ```

### `PML.PMLDynamicObject` — Late-bound PML object access
Implements `DynamicObject` — supports `TryGetMember`, `TrySetMember`, `TryInvokeMember`. Use `dynamic` in C# to access PML object members.

### `Units.Bore` — Bore unit helper

| Method | Description |
|--------|-------------|
| `Bore.CreateBore()` | Static factory |
| `NominalBoreValue(Double bore, int hashDimension)` | Convert bore to nominal using hash dimension |

### `StringUtilities`

| Class | Method | Description |
|-------|--------|-------------|
| `Hash` | `stringToHashValue(String)` / `hashValueToString(int)` | PML hash ↔ int conversion |
| `StringUtils` | `AddSlash(String)` | Ensure trailing slash on path |

### `Interrupt` — Cancellation support

| Class | Description |
|-------|-------------|
| `Interrupt` | Shared `InterruptRequested` flag (get/set) |
| `IInterruptor` | Read-only view of interrupt state |
| `IInterruptable` | Object that accepts an `Interrupt` |
| `ControlSelectedInterruptor` | UI-driven (e.g. Esc key) |
| `InterruptException` | Thrown when interrupted |

### `AvevaConnect` — Cloud/identity (for connected deployments)

| Class | Purpose |
|-------|---------|
| `AvevaConnectManager` | OAuth/Auth0 auth; `GetAccessToken()`, `Initialise()`, `Signout()` |
| `CoreConnectManager` | App-level connect lifecycle; `Initialise(bool interactive, ...)`, `SignOut()` |
| `ConnectSolutions` | Cloud solution listing; `GetSolutions()`, `GetConnectRolesForUE()` |

---

*Generated: 2026-03-23 from `C:\Aibelprogs\AvevaDLL\ue4_DLL\` using PowerShell reflection.*
