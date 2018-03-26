//
//  PCTShow.m
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

#import "PCTShow.h"
#import "PCTObjectProtocol.h"
#import "PCTSeason.h"
#import "PCTAirInformation.h"

@interface PCTPartialShow() <PCTObjectProtocol>

@end

@implementation PCTShow

- (instancetype)initFromDictionary:(NSDictionary *)dictionary {
    self = [super initFromDictionary:dictionary];
    
    if (self) {
        _synopsis = dictionary[@"synopsis"];
        _runtime = [dictionary[@"runtime"] integerValue];
        _genres = dictionary[@"genres"];
        
        id airInformation = [PCTAirInformation alloc];
        
        if ([airInformation conformsToProtocol:@protocol(PCTObjectProtocol)]) {
            _airInformation = [airInformation initFromDictionary:dictionary];
        }
        
        if (_synopsis != nil &&
            !isnan(_runtime) &&
            _genres != nil &&
            _airInformation != nil)
        {
            NSMutableArray *seasons = [NSMutableArray array];
            
            for (NSDictionary *seasonDictionary in dictionary[@"seasons"]) {
                id season = [PCTSeason alloc];
                
                if ([season conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                    season = [season initFromDictionary:seasonDictionary];
                }
                
                season == nil ?: [seasons addObject:season];
            }
            
            [seasons sortUsingComparator:^NSComparisonResult(id  _Nonnull obj1,
                                                              id  _Nonnull obj2) {
                NSUInteger firstSeason = ((PCTSeason *)obj1).number;
                NSUInteger secondSeason = ((PCTSeason *)obj2).number;
                
                return firstSeason < secondSeason ? NSOrderedDescending : NSOrderedAscending;
            }];
            
            _seasons = seasons;
            
            return self;
        }
        
        
    }
    
    return nil;
}

@end
