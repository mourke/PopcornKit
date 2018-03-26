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
    NSString *_backdropString;
    NSString *_logoString;
    NSString *_backgroundThumbString;
}

- (instancetype)initFromDictionary:(NSDictionary *)dictionary {
    self = [super init];
    
    if (self) {
        NSString *posterString = dictionary[@"poster"];
        NSString *backdropString = dictionary[@"backdrop"];
        NSString *logoString = dictionary[@"logo"];
        NSString *backgroundThumbString = dictionary[@"thumb"];
        
        if ([posterString isKindOfClass:NSString.class]) _posterString = posterString;
        if ([backdropString isKindOfClass:NSString.class]) _backdropString = backdropString;
        if ([logoString isKindOfClass:NSString.class]) _logoString = logoString;
        if ([backgroundThumbString isKindOfClass:NSString.class]) _backgroundThumbString = backgroundThumbString;
    }
    
    return self;
}

- (NSURL *)posterURLForSize:(PCTPosterImageSize)size {
    if (_posterString == nil) return nil;
    NSString *base = @"http://image.tmdb.org/t/p/";
    NSString *image = [_posterString lastPathComponent];
    return [NSURL URLWithString:[NSString stringWithFormat:@"%@/%@/%@", base, size, image]];
}

- (NSURL *)backdropURLForSize:(PCTBackdropImageSize)size {
    if (_backdropString == nil) return nil;
    NSString *base = @"http://image.tmdb.org/t/p/";
    NSString *image = [_backdropString lastPathComponent];
    return [NSURL URLWithString:[NSString stringWithFormat:@"%@/%@/%@", base, size, image]];
}

- (NSURL *)thumbURL {
    return [NSURL URLWithString:_backgroundThumbString];
}

- (NSURL *)logoURL {
    return [NSURL URLWithString:_logoString];
}

@end
