//
//  PCTEpisode.m
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

#import "PCTEpisode.h"
#import "PCTObjectProtocol.h"
#import "PCTTorrent.h"

@interface PCTEpisode() <PCTObjectProtocol>

@end

@implementation PCTEpisode {
    NSString *_screenshotString;
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
            NSMutableArray *torrents = [NSMutableArray array];
            
            for (NSDictionary *torrentDictionary in dictionary[@"torrents"]) {
                id torrent = [PCTTorrent alloc];
                
                if ([torrent conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                    torrent = [torrent initFromDictionary:torrentDictionary];
                    
                    torrent == nil ?: [torrents addObject:torrent];
                }
            }
            
            _torrents = torrents;
            
            NSString *screenshotString = dictionary[@"image"];
            if ([screenshotString isKindOfClass:NSString.class]) _screenshotString = screenshotString;
            
            return self;
        }
    }
    
    return nil;
}

- (NSURL *)screenshotURLForSize:(PCTScreenshotImageSize)size {
    if (_screenshotString == nil) return nil;
    NSString *base = @"http://image.tmdb.org/t/p/";
    NSString *image = [_screenshotString lastPathComponent];
    return [NSURL URLWithString:[NSString stringWithFormat:@"%@/%@/%@", base, size, image]];
}

@end
