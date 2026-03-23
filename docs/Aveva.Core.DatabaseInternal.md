# Aveva.Core.DatabaseInternal

**Assembly:** Aveva.Core.DatabaseInternal, Version=12.0.0.0, Culture=neutral, PublicKeyToken=17c64733a9775004

**Total types:** 8

---

## Aveva.Core.Database.DbCommunications

### Properties

| Type | Name |
|------|------|
| Db | CommsDB |
| String | CurrUserIdentifer |
| String | CurrUserLoginName |

### Methods

| Return | Signature |
|--------|-----------|
| Boolean | **CreateProject**(String projname, String username, String password, Int32 dbnumber, Boolean marine, PdmsMessage& error) |
| Boolean | **expunge**(DbElement DBele) |
| Void | **Expunge**(DbElement commele, String reason, Boolean force) |
| DbCommunications | **GetDbCommunications**() |
| Void | **Refresh**() |

---

## Aveva.Core.Database.DbDabUtils

### Methods

| Return | Signature |
|--------|-----------|
| DbDabUtils | **GetDbDabUtils**() |
| Boolean | **GetPrimarySessionFlag**(DbSession session, Boolean& primaryFlag, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, Int32[] val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, Int32 val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, DbDouble[] val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, String val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, DbDouble val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, DbExpression val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, String[] val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, Boolean[] val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, Boolean val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, DbElement[] val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, DbBlob& val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, DbElement val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, Double[] val, PdmsMessage& error) |
| Boolean | **SetDabAttribute**(DbElement ele, DbAttribute attributeName, Double val, PdmsMessage& error) |
| Boolean | **SetPrimarySessionFlag**(DbSession session, Boolean primaryFlag, PdmsMessage& error) |

---

## Aveva.Core.Database.DbElementCollectionEventArgs
_Extends: EventArgs_

### Properties

| Type | Name |
|------|------|
| List`1 | ChangeList |

---

## Aveva.Core.Database.DbMiscellaneous

### Methods

| Return | Signature |
|--------|-----------|
| Boolean | **DeleteNotification**(DbElement notEle, Int32 bulkOperation) |
| Boolean | **DeleteNotification**(DbElement notEle) |
| Boolean | **DeleteNotifications**(DateTime fromDate, DateTime toDate, String projectID, String moduleID, String discipline) |
| Boolean | **DeleteNotifications**(String moduleID, String messageBody, String projID, String sessionID, String[] topic, String fromDiscipline, String userID) |
| Boolean | **DeleteSubscriptions**(String moduleID, String projID, String sessionID, String fromDiscipline, String userID, String[] topicList, String targetDiscipline, DateTime fromDate, DateTime toDate) |
| DbMiscellaneous | **GetDbMiscellaneous**() |
| String[] | **GetNotificationData**(DbElement notEle) |
| DbElement[] | **GetNotifications**(String projId, String userID, String moduleID, String[] topic, String sessionID, String type, DateTime fromDate, DateTime toDate) |
| DbElement[] | **GetNotifications**(String discipline, String projId, Boolean getAll) |
| String[] | **GetSubscriptionData**(DbElement subsEle) |
| DbElement[] | **GetSubscriptions**(String projId, String userID, String moduleID, String[] topic, String sessionID, String type, DateTime fromDate, DateTime toDate) |
| DbElement[] | **GetSubscriptions**(String projId) |
| Boolean | **GetWork**() |
| Boolean | **StoreNotification**(String moduleId, String message, String projId, String sessionId, String[] topic, String fromDiscipline, String userId, String date, Int32 bulkOperation) |
| Boolean | **StoreNotification**(String moduleId, String message, String projId, String sessionId, String[] topic, String fromDiscipline, String userId, String date, Int32 bulkOperation, String targetSubsrecord) |
| Boolean | **StoreNotificationToSpecificSubscriptions**(String moduleId, String message, String projectId, String sessionId, String[] topic, String fromDiscipline, String userId, String date, Int32 bulkOperation, String[] subscriptionList) |
| Boolean | **StoreSubscription**(String moduleId, String projId, String sessionId, String[] topic, String fromDiscipline, String targetDiscipline, String userId, String date) |

---

## Aveva.Core.Database.DbNameSequence

### Methods

| Return | Signature |
|--------|-----------|
| Int32[] | **CheckCountersAvailability**(Int32 counterType, Int32 requestedCounter, Int32 requestedQuantity, Boolean sequential) |
| Boolean | **Create**() |
| Boolean | **Exist**() |
| Int32[] | **GetAvailableCounterRanges**() |
| Int32[] | **GetCounters**(Int32 requestedCase, Int32 requestedCounter, Int32 requestedQuantity, Boolean sequential) |
| Int32 | **GetCurrent**() |
| DbNameSequence | **GetDbNameSequence**(String sequence) |
| Int32 | **GetMax**() |
| String | **GetName**() |
| String | **GetNamSeqDbEleRefId**() |
| Int32 | **GetStart**() |
| Int32 | **GetStep**() |
| Int32[] | **GetUnavailableCounters**(Int32 counterType, Int32 requestedCounter, Int32 requestedQuantity, Boolean sequential, Int32 fixedLength) |
| Boolean | **IsWraparound**() |
| String | **Next**() |
| Void | **ReleaseCounter**(Int32[] countersToBeReleased) |
| Boolean | **Remove**() |
| Boolean | **ReStart**() |
| Void | **SetAvailableCounterRanges**(Int32[] availableCounterRanges) |
| Boolean | **SetCurrent**(Int32 current) |
| Boolean | **SetMax**(Int32 max) |
| Boolean | **SetNoWraparound**() |
| Boolean | **SetStart**(Int32 start) |
| Boolean | **SetStep**(Int32 step) |
| Boolean | **SetWraparound**() |

---

## Aveva.Core.Database.DbTransaction

### Methods

| Return | Signature |
|--------|-----------|
| Void | **AbortTransaction**() |
| Void | **CommitTransaction**() |
| DbTransaction | **GetDbTransaction**() |
| Void | **StartTransaction**() |

---

## Aveva.Core.Database.IDbElementCollectionManager

### Methods

| Return | Signature |
|--------|-----------|
| Void | **Add**(DbElement element) |
| Nullable`1 | **AllPrimitivesIncluded**(DbElement element) |
| Boolean | **ElementCanBeAdded**(DbElement element) |
| Boolean | **IncludesElement**(DbElement dbValue) |
| Boolean | **IsPrimitiveOf**(DbElement elementParent, DbElement element) |
| Void | **Remove**(DbElement element) |

---

## Aveva.Core.Database.IDbElementContainer

### Properties

| Type | Name |
|------|------|
| DbElement | RootElement |

---

