# Aveva.Core

**Assembly:** Aveva.Core, Version=12.0.0.0, Culture=neutral, PublicKeyToken=17c64733a9775004

**Total types:** 9

---

## Aveva.Core.BeforeFinishEventHandler
_Extends: MulticastDelegate_

### Methods

| Return | Signature |
|--------|-----------|
| IAsyncResult | **BeginInvoke**(Object sender, EventArgs e, AsyncCallback callback, Object object) |
| Void | **EndInvoke**(IAsyncResult result) |
| Void | **Invoke**(Object sender, EventArgs e) |

---

## Aveva.Core.FatalFinishEventHandler
_Extends: MulticastDelegate_

### Methods

| Return | Signature |
|--------|-----------|
| IAsyncResult | **BeginInvoke**(Object sender, StartupFailureEventArgs e, AsyncCallback callback, Object object) |
| Void | **EndInvoke**(IAsyncResult result) |
| Void | **Invoke**(Object sender, StartupFailureEventArgs e) |

---

## Aveva.Core.FinishEventHandler
_Extends: MulticastDelegate_

### Methods

| Return | Signature |
|--------|-----------|
| IAsyncResult | **BeginInvoke**(Object sender, EventArgs e, AsyncCallback callback, Object object) |
| Void | **EndInvoke**(IAsyncResult result) |
| Void | **Invoke**(Object sender, EventArgs e) |

---

## Aveva.Core.ModuleType
_Extends: Enum_

---

## Aveva.Core.PdmsApplication

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Close**() |
| Void | **Exit**(String message) |
| String | **ExpandPdmsEnvironmentVariables**(String expression) |
| Void | **Finish**() |
| Double | **GetAtmPressureFromUomlib**() |
| String | **GetExistingPdmsFilePath**(String filePath) |
| String[] | **GetPdmsEnvironmentVariables**(String expression) |
| IEnumerable`1 | **GetPdmsFilePaths**(String filePath) |
| Void | **InitialiseAdmin**(Boolean commsfile) |
| Void | **InitialiseConfiguration**(Boolean commsfile) |
| Void | **InitialiseCoreModule**(Boolean commsfile) |
| Void | **InitialiseFandmForDotNetTests**() |
| Void | **InitialiseLexicon**(Boolean commsfile) |
| Void | **InitialiseMonitor**(Boolean commsfile) |
| Void | **InitialiseSMM**(Boolean commsfile) |
| Void | **InitialiseUomData**() |
| Boolean | **initializeAvevaConnectService**() |
| String | **licDecryptString**(String encrypted, Int32 checksum) |
| Boolean | **licFeatureCheckIn**(String feature, Int32 checkSum) |
| Int32 | **licFeatureCheckOut**(String feature, Int32 checkSum) |
| Int32 | **licFeatureCheckOut**(String feature, Int32 checkSum, String productVersion, Int32 productVerChecksum) |
| Boolean | **licFeatureExists**(String feature, Int32 checkSum) |
| String | **licGetError**() |
| Boolean | **licProductFeatureExists**(Int32 moduleNumber) |
| Int32 | **licRegisterAccessToken**(String token) |
| Void | **licReset**() |
| Int32 | **licUsingLaas**() |
| Void | **OpenProjectAfterModuleSwitch**() |
| Void | **PlugStartMacro**() |
| Hashtable | **ProjectList**(Boolean isPathRequired) |
| Void | **RaiseBeforeFinished**(Object sender, EventArgs e) |
| Void | **RaiseFatalFinished**(Object sender, StartupFailureEventArgs e) |
| Void | **RaiseFinished**(Object sender, EventArgs e) |
| Void | **RaiseStartupFailure**(Object sender, StartupFailureEventArgs e) |
| Void | **SetPdmsEnvironmentVariable**(String name, String value) |
| Void | **Start**(Boolean isGraphics, Int32 moduleNumber, String moduleName, Boolean isBatch, Boolean isNoConsole, String logfile, String deviceId) |
| Void | **Start**(Boolean isGraphics, Int32 moduleNumber, String moduleName, Boolean isBatch, Boolean isNoConsole, String logfile) |
| Void | **Start**(Boolean isGraphics, Int32 moduleNumber, Boolean isBatch, Boolean isNoConsole, String logfile) |
| Void | **StartEventLoop**() |
| Void | **StartViaCommsFile**(Boolean isGraphics, Int32 moduleNumber, String moduleName) |

---

## Aveva.Core.PdmsApplication+CoordinateSystem
_Extends: Enum_

---

## Aveva.Core.PdmsVersion

### Methods

| Return | Signature |
|--------|-----------|
| Void | **AddSubsystemInfo**(String subsystem, String version, String buildNumber, String date) |
| String | **GetBundleVersion**() |
| String | **GetCompanyName**() |
| String | **GetCopyright**() |
| String | **GetModuleName**(ModuleType module) |
| String | **GetModuleVersion**(ModuleType module) |
| String | **GetName**() |
| String | **GetShortBanner**() |
| String | **GetStatus**() |
| String | **GetVersion**() |
| Void | **SetProductInfo**(String version, String buildNumber, String date, String copyright, String coreVersion, String extra, String bundleVersion) |
| Void | **SetProductInfo**(String version, String buildNumber, String date, String copyright, String coreVersion, String extra) |

---

## Aveva.Core.StartupFailureEventArgs

### Properties

| Type | Name |
|------|------|
| Int32 | Message |
| String | MessageText |
| Int32 | Module |

---

## Aveva.Core.StartupFailureHandler
_Extends: MulticastDelegate_

### Methods

| Return | Signature |
|--------|-----------|
| IAsyncResult | **BeginInvoke**(Object sender, StartupFailureEventArgs arg, AsyncCallback callback, Object object) |
| Void | **EndInvoke**(IAsyncResult result) |
| Void | **Invoke**(Object sender, StartupFailureEventArgs arg) |

---

