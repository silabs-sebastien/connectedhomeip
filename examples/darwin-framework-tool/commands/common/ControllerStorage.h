/*
 *   Copyright (c) 2024 Project CHIP Authors
 *   All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

#import <Matter/Matter.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kDarwinFrameworkToolControllerDomain;

@interface ControllerStorage : NSObject <MTRDeviceControllerStorageDelegate>
- (instancetype)initWithControllerID:(NSUUID *)controllerID;
@property (nonatomic, readonly) NSUUID * controllerID;

- (nullable id<NSSecureCoding>)controller:(MTRDeviceController *)controller
                              valueForKey:(NSString *)key
                            securityLevel:(MTRStorageSecurityLevel)securityLevel
                              sharingType:(MTRStorageSharingType)sharingType;
- (BOOL)controller:(MTRDeviceController *)controller
        storeValue:(id<NSSecureCoding>)value
            forKey:(NSString *)key
     securityLevel:(MTRStorageSecurityLevel)securityLevel
       sharingType:(MTRStorageSharingType)sharingType;
- (BOOL)controller:(MTRDeviceController *)controller
    removeValueForKey:(NSString *)key
        securityLevel:(MTRStorageSecurityLevel)securityLevel
          sharingType:(MTRStorageSharingType)sharingType;
- (NSDictionary<NSString *, id<NSSecureCoding>> *)valuesForController:(MTRDeviceController *)controller securityLevel:(MTRStorageSecurityLevel)securityLevel sharingType:(MTRStorageSharingType)sharingType;
- (BOOL)controller:(MTRDeviceController *)controller storeValues:(NSDictionary<NSString *, id<NSSecureCoding>> *)values securityLevel:(MTRStorageSecurityLevel)securityLevel sharingType:(MTRStorageSharingType)sharingType;

- (NSData *)valueForKey:(NSString *)key;
- (void)storeValue:(NSData *)value forKey:key;
- (void)print;
@end

NS_ASSUME_NONNULL_END
