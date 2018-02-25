//
//  PCTAPI+Shows.h
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

@class PCTShow, PCTPartialShow;

NS_ASSUME_NONNULL_BEGIN

@interface PCTAPI (Shows)

/**
 Loads Shows from the API.
 
 @param page        The page number to load.
 @param filter      Sort the response by Popularity, Year, Date Rating, Alphabet or Trending.
 @param genre       Only return shows that match the provided genre.
 @param query       Only return shows that match the provided string.
 @param order       Ascending or descending.
 @param callback    The block called when the request completes. If the request completes successfully, an array of `PCTPartialShow` objects will be returned, however, if it fails, the underlying error will be returned.
 
 @note  This method returns `PCTPartialShow` objects and not full `PCTShow` objects. `PCTPartialShow` can be promoted to full `PCTShow` objects by calling `getShowForImdbID:callback:` passing in the IMDB ID obtained from the `PCTPartialShow` object.
 
 @return    The request's `NSURLSessionTask` to be resumed.
 */
+ (NSURLSessionDataTask *)loadShowsOnPage:(NSUInteger)page
                                   filter:(PCTFilters)filter
                                    genre:(PCTGenres)genre
                              searchQuery:(NSString * _Nullable)query
                                    order:(PCTOrders)order
                                 callback:(void (^)(NSError * _Nullable, NSArray<PCTPartialShow *> *))callback NS_SWIFT_NAME(shows(on:filter:genre:query:order:callback:));

/**
 Gets information on a specified show.
 
 @param imdbIdentifier  The imdb identifier of the show.
 @param callback        The closure called when the request completes. If the request completes successfully, a `PCTShow` object will be returned, however, if it fails, the underlying error will be returned.
 
 @return    The request's `NSURLSessionTask` to be resumed.
 */
+ (NSURLSessionDataTask *)getShowForImdbID:(NSString *)imdbIdentifier callback:(void (^)(NSError * _Nullable, PCTShow * _Nullable))callback NS_SWIFT_NAME(show(for:callback:));

/**
 Gets a random show from the API.
 
 @param callback    The closure called when the request completes. If the request completes successfully, a `PCTShow` object will be returned, however, if it fails, the underlying error will be returned.
 
 @return    The request's `NSURLSessionTask` to be resumed.
 */
+ (NSURLSessionDataTask *)getRandomShowWithCallback:(void (^)(NSError * _Nullable, PCTShow * _Nullable))callback NS_SWIFT_NAME(randomShow(_:));


@end

NS_ASSUME_NONNULL_END

