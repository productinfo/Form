@import Foundation;

#import "FORMFieldElement.h"
#import "FORMFieldValue.h"

typedef NS_ENUM(NSInteger, FORMTargetType) {
    FORMTargetTypeField = 0,
    FORMTargetTypeSection,
    FORMTargetTypeNone
};

typedef NS_ENUM(NSInteger, FORMTargetActionType) {
    FORMTargetActionShow = 0,
    FORMTargetActionHide,
    FORMTargetActionUpdate,
    FORMTargetActionEnable,
    FORMTargetActionDisable,
    FORMTargetActionClear,
    FORMTargetActionNone
};

@interface FORMTarget : NSObject

@property (nonatomic, copy) NSString *targetID;
@property (nonatomic, copy) id value;
@property (nonatomic, copy) NSString *targetTypeString;
@property (nonatomic, copy) NSString *actionTypeString;
@property (nonatomic, copy) NSString *condition;

@property (nonatomic) FORMFieldValue *fieldValue;
@property (nonatomic) FORMTargetType targetType;
@property (nonatomic) FORMTargetActionType actionType;

@property (nonatomic) FORMFieldValidation *validation;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary NS_DESIGNATED_INITIALIZER;

- (NSDictionary *)fieldPropertiesToUpdate;

+ (void)filteredTargets:(NSArray*)targets
               filtered:(void (^)(NSArray *shownTargets,
                                  NSArray *hiddenTargets,
                                  NSArray *updatedTargets,
                                  NSArray *enabledTargets,
                                  NSArray *disabledTargets))filtered;

+ (FORMTarget *)showFieldTargetWithID:(NSString *)targetID;
+ (FORMTarget *)hideFieldTargetWithID:(NSString *)targetID;
+ (FORMTarget *)enableFieldTargetWithID:(NSString *)targetID;
+ (FORMTarget *)disableFieldTargetWithID:(NSString *)targetID;
+ (FORMTarget *)updateFieldTargetWithID:(NSString *)targetID;
+ (FORMTarget *)clearFieldTargetWithID:(NSString *)targetID;

+ (NSArray *)showFieldTargetsWithIDs:(NSArray *)targetIDs;
+ (NSArray *)hideFieldTargetsWithIDs:(NSArray *)targetIDs;
+ (NSArray *)enableFieldTargetsWithIDs:(NSArray *)targetIDs;
+ (NSArray *)disableFieldTargetsWithIDs:(NSArray *)targetIDs;
+ (NSArray *)updateFieldTargetsWithIDs:(NSArray *)targetIDs;
+ (NSArray *)clearFieldTargetsWithIDs:(NSArray *)targetIDs;

+ (FORMTarget *)showSectionTargetWithID:(NSString *)targetID;
+ (FORMTarget *)hideSectionTargetWithID:(NSString *)targetID;
+ (FORMTarget *)enableSectionTargetWithID:(NSString *)targetID;
+ (FORMTarget *)disableSectionTargetWithID:(NSString *)targetID;
+ (FORMTarget *)updateSectionTargetWithID:(NSString *)targetID;

+ (NSArray *)showSectionTargetsWithIDs:(NSArray *)targetIDs;
+ (NSArray *)hideSectionTargetsWithIDs:(NSArray *)targetIDs;
+ (NSArray *)enableSectionTargetsWithIDs:(NSArray *)targetIDs;
+ (NSArray *)disableSectionTargetsWithIDs:(NSArray *)targetIDs;
+ (NSArray *)updateSectionTargetsWithIDs:(NSArray *)targetIDs;

@end
