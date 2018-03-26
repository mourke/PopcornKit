//
//  PCTMovie.h
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

@class PCTImages, PCTTorrent;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Movie)
@interface PCTMovie : NSObject

/** The name of the movie. */
@property (strong, nonatomic, readonly) NSString *title;

/** The IMDB identifier of the movie. */
@property (strong, nonatomic, readonly) NSString *imdbID NS_SWIFT_NAME(imdbId);

/** The TMDB identifier of the movie. */
@property (nonatomic, readonly) NSInteger tmdbID NS_SWIFT_NAME(tmdbId);

/** The date on which the movie was released. */
@property (strong, nonatomic, readonly) NSDate *releaseDate;

/** A short summary of the movie's plot. */
@property (strong, nonatomic, readonly) NSString *synopsis;

/** The length of the movie (in minutes). */
@property (nonatomic, readonly) NSInteger runtime;

/** The Motion Picture Association of America rating for the movie. */
@property (strong, nonatomic, readonly) PCTMovieCertification certification;

/** The movie's rating (from 1 to 5), according to trakt. */
@property (nonatomic, readonly) float rating;

/** A YouTube URL for the movie's trailer. */
@property (strong, nonatomic, nullable, readonly) NSURL *trailerURL;

/** The genres that the movie is a type of. */
@property (strong, nonatomic, readonly) NSArray<NSString *> *genres;

/** The image art for the movie, if any. */
@property (strong, nonatomic, readonly) PCTImages *images;

/** The torrents for the movie. */
@property (strong, nonatomic, readonly) NSArray<PCTTorrent *> *torrents;

@end

NS_ASSUME_NONNULL_END
