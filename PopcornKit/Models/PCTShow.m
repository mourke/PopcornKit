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
#import "PCTEpisode.h"
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
        
        NSTimeInterval timeInterval = [dictionary[@"released"] doubleValue];
        
        id airInformation = [PCTAirInformation alloc];
        
        if ([airInformation conformsToProtocol:@protocol(PCTObjectProtocol)]) {
            _airInformation = [airInformation initFromDictionary:dictionary];
        }
        
        if ([_synopsis isKindOfClass:NSString.class] &&
            !isnan(_runtime) &&
            !isnan(timeInterval) &&
            [_genres isKindOfClass:NSArray.class] &&
            _airInformation != nil)
        {
            
            _releaseDate = [NSDate dateWithTimeIntervalSince1970:timeInterval];
            
            NSMutableArray *episodes = [NSMutableArray array];
            
            for (NSDictionary *episodeDictionary in dictionary[@"episodes"]) {
                id episode = [PCTEpisode alloc];
                
                if ([episode conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                    episode = [episode initFromDictionary:episodeDictionary];
                    
                    episode == nil ?: [episodes addObject:episode];
                }
            }
            
            _episodes = episodes;
            
            return self;
        }
        
        
    }
    
    return nil;
}

@end
