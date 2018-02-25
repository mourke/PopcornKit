//
//  PCTImages.m
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

#import "PCTImages.h"
#import "PCTObjectProtocol.h"

@interface PCTImages() <PCTObjectProtocol>

@end

@implementation PCTImages {
    NSString *_posterString;
    NSString *_fanartString;
    NSString *_bannerString;
}

- (instancetype)initFromDictionary:(NSDictionary *)dictionary {
    self = [super init];
    
    if (self) {
        NSString *posterString = dictionary[@"poster"];
        NSString *fanartString = dictionary[@"fanart"];
        NSString *bannerString = dictionary[@"banner"];
        
        if ([posterString isKindOfClass:NSString.class]) _posterString = posterString;
        if ([fanartString isKindOfClass:NSString.class]) _fanartString = fanartString;
        if ([bannerString isKindOfClass:NSString.class]) _bannerString = bannerString;
    }
    
    return self;
}

- (NSURL *)posterImageForWidth:(NSInteger)width {
    return [NSURL URLWithString:[_posterString stringByReplacingOccurrencesOfString:@"w500" withString:[NSString stringWithFormat:@"w%zd", width]]];
}

- (NSURL *)fanartImageForWidth:(NSInteger)width {
    return [NSURL URLWithString:[_fanartString stringByReplacingOccurrencesOfString:@"w500" withString:[NSString stringWithFormat:@"w%zd", width]]];
}

- (NSURL *)bannerImageForWidth:(NSInteger)width {
    return [NSURL URLWithString:[_bannerString stringByReplacingOccurrencesOfString:@"w500" withString:[NSString stringWithFormat:@"w%zd", width]]];
}

@end
