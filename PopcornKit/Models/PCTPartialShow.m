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
        _tvdbID = [dictionary[@"tvdb_id"] integerValue];
        _title = dictionary[@"title"];
        _releaseYear = dictionary[@"year"];
        
        NSUInteger rating = [dictionary[@"rating"][@"percentage"] unsignedIntegerValue];
        
        id images = [PCTImages alloc];
        
        if ([images conformsToProtocol:@protocol(PCTObjectProtocol)]) {
            _images = [images initFromDictionary:dictionary[@"images"]];
        }
        
        if ([_imdbID isKindOfClass:NSString.class] &&
            !isnan(_tvdbID) &&
            [_title isKindOfClass:NSString.class] &&
            [_releaseYear isKindOfClass:NSString.class] &&
            !isnan(rating) &&
            _images != nil)
        {
            _rating = rating/20.0;
            return self;
        }
    }
    
    return nil;
}

@end
