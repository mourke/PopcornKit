//
//  PCTImages.h
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

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(Images)
@interface PCTImages : NSObject

/**
 Returns a poster (cover art) URL taylored to a specific size, if available. Ratio is usually 713:500.
 
 @param width   The width of the desired image (in pixels).
 
 @return    The URL, if available.
 */
- (NSURL * _Nullable)posterImageForWidth:(NSInteger)width;

/**
 Returns a fanart (background art) URL taylored to a specific size, if available. Ratio is usually 16:9
 
 @param width   The width of the desired image (in pixels).
 
 @return    The URL, if available.
 */
- (NSURL * _Nullable)fanartImageForWidth:(NSInteger)width;

/**
 Returns a banner (widescreen poster art) URL taylored to a specific size, if available. Ratio is usually 200:37.
 
 @param width   The width of the desired image (in pixels).
 
 @return    The URL, if available.
 */
- (NSURL * _Nullable)bannerImageForWidth:(NSInteger)width;

@end
