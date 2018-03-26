//
//  PCTSeason.h
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

@class PCTEpisode;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Season)
@interface PCTSeason : NSObject

/** The name of the season. */
@property (strong, nonatomic, readonly) NSString *title;

/** The TMDB identifier of the season. */
@property (nonatomic, readonly) NSInteger tmdbID NS_SWIFT_NAME(tmdbId);

/** The season number of the season. */
@property (nonatomic, readonly) NSUInteger number;

/** A short summary of the season's plot. */
@property (strong, nonatomic, readonly) NSString *synopsis;

/** The date on which the first episode in the season was aired. */
@property (strong, nonatomic, readonly) NSDate *releaseDate;

/** The episodes in the season. */
@property (strong, nonatomic, readonly) NSArray<PCTEpisode *> *episodes;

/**
 Returns a poster image URL for the episode taylored to a specific size, if available. Ratio is usually 713:500.
 
 @param size    The size of the desired image.
 
 @return    The URL, if available.
 */
- (NSURL * _Nullable)posterURLForSize:(PCTPosterImageSize _Nonnull)size NS_SWIFT_NAME(poster(for:));

@end

NS_ASSUME_NONNULL_END
