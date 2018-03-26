//
//  PCTAirInformation.m
//  PopcornKit
//
//  Copyright © 2018 Mark Bourke.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE
//

#import "PCTAirInformation.h"
#import "PCTObjectProtocol.h"

@interface PCTAirInformation() <PCTObjectProtocol>

@end

@implementation PCTAirInformation

- (instancetype)initFromDictionary:(NSDictionary *)dictionary {
    self = [super init];
    
    if (self) {
        _status = dictionary[@"status"];
        _network = dictionary[@"network"];
        _countryCode = dictionary[@"country"];
        
        NSDateComponents *components = [NSDateComponents new];
        
        NSString *airTimeString = dictionary[@"time"];
        NSString *airDayString = dictionary[@"day"];
        
        if (_status == PCTAirStatusReturning &&
            [airTimeString isKindOfClass:NSString.class] &&
            [airDayString isKindOfClass:NSString.class]) {
            NSArray *days = [[NSDateFormatter new] weekdaySymbols];
            NSArray<NSString *> *timeStringComponents = [airTimeString componentsSeparatedByString:@":"];
            
            components.day = [days indexOfObject:airDayString];
            components.hour = [[timeStringComponents firstObject] integerValue];
            components.minute = [[timeStringComponents lastObject] integerValue];
        }
        
        _dateComponents = components;
        
        if (_dateComponents != nil &&
            [_network isKindOfClass:NSString.class] &&
            [_status isKindOfClass:NSString.class] &&
            [_countryCode isKindOfClass:NSString.class]) {
            return self;
        }
    }
    
    return nil;
}

@end
