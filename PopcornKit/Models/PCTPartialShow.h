//
//  PCTPartialShow.h
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
#import "PCTCertification.h"

@class PCTImages;

NS_ASSUME_NONNULL_BEGIN

/**
 A partial show object obtained by calling `loadShowsOnPage:filter:genre:searchQuery:order:callback:`.
 */
NS_SWIFT_NAME(PartialShow)
@interface PCTPartialShow : NSObject

/** The name of the show. */
@property (strong, nonatomic, readonly) NSString *title;

/** The IMDB identifier of the show. */
@property (strong, nonatomic, readonly) NSString *imdbID NS_SWIFT_NAME(imdbId);

/** The TMDB identifier of the show. */
@property (nonatomic, readonly) NSInteger tmdbID NS_SWIFT_NAME(tmdbId);

/** The TVDB identifier of the show. */
@property (nonatomic, readonly) NSInteger tvdbID NS_SWIFT_NAME(tvdbId);

/** The show's rating (from 1 to 5), according to trakt. */
@property (nonatomic, readonly) float rating;

/** The date on which the first episode was aired. */
@property (strong, nonatomic, readonly) NSDate *releaseDate;

/** The image art for the movie, if any. */
@property (strong, nonatomic, readonly) PCTImages *images;

/** The TV rating for the show. */
@property (strong, nonatomic, readonly) PCTTVCertification certification;

@end

NS_ASSUME_NONNULL_END
