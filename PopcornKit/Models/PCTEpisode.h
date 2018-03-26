//
//  PCTEpisode.h
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

@class PCTEpisode, PCTTorrent;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Episode)
@interface PCTEpisode : NSObject

/** The name of the episode. */
@property (strong, nonatomic, readonly) NSString *title;

/** The TMDB identifier of the episode. */
@property (nonatomic, readonly) NSInteger tmdbID NS_SWIFT_NAME(tmdbId);

/** The episode number of the episode. */
@property (nonatomic, readonly) NSUInteger number;

/** A short summary of the episode's plot. */
@property (strong, nonatomic, readonly) NSString *synopsis;

/** The date on which the episode was aired. */
@property (strong, nonatomic, readonly) NSDate *releaseDate;

/** The torrents for the episode. */
@property (strong, nonatomic, readonly) NSArray<PCTTorrent *> *torrents;

/**
 Returns a screenshot thumb image URL for the episode taylored to a specific size, if available. Ratio is usually 16:9
 
 @param size    The size of the desired image.
 
 @return    The URL, if available.
 */
- (NSURL * _Nullable)screenshotURLForSize:(PCTScreenshotImageSize _Nonnull)size NS_SWIFT_NAME(screenshot(for:));

@end

NS_ASSUME_NONNULL_END
