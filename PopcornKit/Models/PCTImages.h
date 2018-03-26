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
#import "PCTImageSize.h"

NS_SWIFT_NAME(Images)
@interface PCTImages : NSObject

/**
 Returns a poster (cover art) URL taylored to a specific size, if available. Ratio is usually 713:500.
 
 @param size    The size of the desired image.
 
 @return    The URL, if available.
 */
- (NSURL * _Nullable)posterURLForSize:(PCTPosterImageSize _Nonnull)size NS_SWIFT_NAME(poster(for:));

/**
 Returns a backdrop (background art) URL taylored to a specific size, if available. Ratio is usually 16:9
 
 @param size    The size of the desired image.
 
 @return    The URL, if available.
 */
- (NSURL * _Nullable)backdropURLForSize:(PCTBackdropImageSize _Nonnull)size NS_SWIFT_NAME(backdrop(for:));

/** Returns a background thumb URL, if available. */
@property (strong, nonatomic, nullable, readonly) NSURL *thumbURL NS_SWIFT_NAME(thumb);

/** Returns a Logo Image URL, if available. */
@property (strong, nonatomic, nullable, readonly) NSURL *logoURL NS_SWIFT_NAME(logo);

@end
