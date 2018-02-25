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

@implementation PCTEpisode

- (instancetype)initFromDictionary:(NSDictionary *)dictionary {
    self = [super init];
    
    if (self) {
        _airedDate = [NSDate dateWithTimeIntervalSince1970:[dictionary[@"first_aired"] doubleValue]];
        _synopsis = dictionary[@"overview"];
        _title = dictionary[@"title"];
        _episode = [dictionary[@"episode"] unsignedIntegerValue];
        _season = [dictionary[@"season"] unsignedIntegerValue];
        _tvdbID = [NSString stringWithFormat:@"%zx", [dictionary[@"tvdb_id"] unsignedIntegerValue]];
        
        if (_airedDate != nil &&
            _synopsis != nil &&
            _title != nil &&
            !isnan(_episode) &&
            !isnan(_season) &&
            _tvdbID != nil)
        {
            NSMutableArray *torrents = [NSMutableArray array];
            
            [dictionary[@"torrents"] enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key,
                                                                         id  _Nonnull obj,
                                                                         BOOL * _Nonnull stop) {
                if ([key isEqualToString:@"0"]) return; // Ignore the first torrent as it completely arbitrary and is identical to one of the others. 
                
                NSDictionary *torrentDictionary = obj;
                
                id torrent = [PCTTorrent alloc];
                
                if ([torrent conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                    torrent = [torrent initFromDictionary:torrentDictionary];
                    
                    ((PCTTorrent *)torrent).quality = (PCTTorrentQuality)key;
                    
                    torrent == nil ?: [torrents addObject:torrent];
                }
            }];
            
            _torrents = torrents;
            
            return self;
        }
    }
    
    return nil;
}

@end
