//
//  PCTAPI+Movies.h
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
#import "PCTAPI.h"

@class PCTMovie;

NS_ASSUME_NONNULL_BEGIN

@interface PCTAPI (Movies)

/**
 Loads Movies from the API.
 
 @param page        The page number to load.
 @param filter      Sort the response by Popularity, Year, Date Rating, Alphabet or Trending.
 @param genre       Only return movies that match the provided genre.
 @param query       Only return movies that match the provided string.
 @param order       Ascending or descending.
 @param callback    The block called when the request completes. If the request completes successfully, an array of `PCTMovie` objects will be returned, however, if it fails, the underlying error will be returned.
 
 @return    The request's `NSURLSessionTask` to be resumed.
 */
+ (NSURLSessionDataTask *)loadMoviesOnPage:(NSUInteger)page
                                    filter:(PCTFilter)filter
                                     genre:(PCTGenre)genre
                               searchQuery:(NSString * _Nullable)query
                                     order:(PCTOrder)order
                                  callback:(void (^)(NSError * _Nullable, NSArray<PCTMovie *> *))callback NS_SWIFT_NAME(movies(on:filter:genre:query:order:callback:));

/**
 Gets information on a specified movie.
 
 @param imdbIdentifier  The imdb identifier of the movie.
 @param callback        The closure called when the request completes. If the request completes successfully, a `PCTMovie` object will be returned, however, if it fails, the underlying error will be returned.
 
 @return    The request's `NSURLSessionTask` to be resumed.
 */
+ (NSURLSessionDataTask *)getMovieForImdbID:(NSString *)imdbIdentifier callback:(void (^)(NSError * _Nullable, PCTMovie * _Nullable))callback NS_SWIFT_NAME(movie(for:callback:));

/**
 Gets a random movie from the API.

 @param callback    The closure called when the request completes. If the request completes successfully, a `PCTMovie` object will be returned, however, if it fails, the underlying error will be returned.
 
 @return    The request's `NSURLSessionTask` to be resumed.
 */
+ (NSURLSessionDataTask *)getRandomMovieWithCallback:(void (^)(NSError * _Nullable, PCTMovie * _Nullable))callback NS_SWIFT_NAME(randomMovie(_:));


@end

NS_ASSUME_NONNULL_END
