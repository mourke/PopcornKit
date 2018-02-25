//
//  PCTPartialShow.m
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

#import "PCTPartialShow.h"
#import "PCTObjectProtocol.h"
#import "PCTImages.h"

@interface PCTPartialShow() <PCTObjectProtocol>

@end

@implementation PCTPartialShow

- (instancetype)initFromDictionary:(NSDictionary *)dictionary {
    self = [super init];
    
    if (self) {
        _imdbID = dictionary[@"imdb_id"];
        _tmdbID = dictionary[@"tmdb_id"];
        _tvdbID = dictionary[@"tvdb_id"];
        _title = dictionary[@"title"];
        
        NSDateFormatter *formatter = [NSDateFormatter new];
        [formatter setDateFormat:@"yyyy"];
        
        _releaseDate = [formatter dateFromString:dictionary[@"year"]];
        
        id images = [PCTImages alloc];
        
        if ([images conformsToProtocol:@protocol(PCTObjectProtocol)]) {
            _images = [images initFromDictionary:dictionary[@"images"]];
        }
        
        if (_imdbID != nil &&
            _tmdbID != nil &&
            _tvdbID != nil &&
            _title != nil &&
            _releaseDate != nil &&
            _images != nil)
        {
            return self;
        }
    }
    
    return nil;
}

@end
