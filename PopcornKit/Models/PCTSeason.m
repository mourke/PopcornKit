//
//  PCTSeason.m
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

#import "PCTSeason.h"
#import "PCTObjectProtocol.h"
#import "PCTEpisode.h"

@interface PCTSeason() <PCTObjectProtocol>

@end

@implementation PCTSeason {
    NSString *_posterString;
}

- (instancetype)initFromDictionary:(NSDictionary *)dictionary {
    self = [super init];
    
    if (self) {
        _releaseDate = [NSDate dateWithTimeIntervalSince1970:[dictionary[@"first_aired"] doubleValue]];
        _synopsis = dictionary[@"overview"];
        _title = dictionary[@"title"];
        _number = [dictionary[@"number"] unsignedIntegerValue];;
        _tmdbID = [dictionary[@"tmdb_id"] integerValue];
        
        if (_releaseDate != nil &&
            _synopsis != nil &&
            _title != nil &&
            !isnan(_number) &&
            !isnan(_tmdbID))
        {
            NSMutableArray *episodes = [NSMutableArray array];
            
            for (NSDictionary *episodeDictionary in dictionary[@"episodes"]) {
                id episode = [PCTEpisode alloc];
                
                if ([episode conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                    episode = [episode initFromDictionary:episodeDictionary];
                    
                    episode == nil ?: [episodes addObject:episode];
                }
            }
            
            [episodes sortUsingComparator:^NSComparisonResult(id  _Nonnull obj1,
                                                             id  _Nonnull obj2) {
                NSUInteger firstEpisode = ((PCTEpisode *)obj1).number;
                NSUInteger secondEpisode = ((PCTEpisode *)obj2).number;
                
                return firstEpisode < secondEpisode ? NSOrderedDescending : NSOrderedAscending;
            }];
            
            _episodes = episodes;
            
            NSString *posterString = dictionary[@"image"];
            if ([posterString isKindOfClass:NSString.class]) _posterString = posterString;
            
            return self;
        }
    }
    
    return nil;
}


- (NSURL *)posterURLForSize:(PCTPosterImageSize)size {
    if (_posterString == nil) return nil;
    NSString *base = @"http://image.tmdb.org/t/p/";
    NSString *image = [_posterString lastPathComponent];
    return [NSURL URLWithString:[NSString stringWithFormat:@"%@/%@/%@", base, size, image]];
}

@end
