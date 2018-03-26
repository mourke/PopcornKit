//
//  PCTAPI+Movies.m
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

#import "PCTAPI+Movies.h"
#import "PCTEndpoints.h"
#import "PCTMovie.h"
#import "PCTObjectProtocol.h"

@implementation PCTAPI (Movies)

+ (NSURLSessionDataTask *)loadMoviesOnPage:(NSUInteger)page
                                    filter:(PCTFilter)filter
                                     genre:(PCTGenre)genre
                               searchQuery:(NSString *)query
                                     order:(PCTOrder)order
                                  callback:(void (^)(NSError * _Nullable, NSArray<PCTMovie *> * _Nonnull))callback {
    NSURLSession *session = [NSURLSession sharedSession];
    
    NSURLComponents *components = [NSURLComponents componentsWithString:[NSString stringWithFormat:@"%@/%tu", kPCTEndpointMovies, page]];
    
    components.queryItems = @[[NSURLQueryItem queryItemWithName:@"sort" value:filter],
                              [NSURLQueryItem queryItemWithName:@"order" value:@(order).stringValue],
                              [NSURLQueryItem queryItemWithName:@"genre" value:genre],
                              [NSURLQueryItem queryItemWithName:@"keywords" value:query]];
    
    return [session dataTaskWithURL:components.URL completionHandler:^(NSData * _Nullable data,
                                                                       NSURLResponse * _Nullable response,
                                                                       NSError * _Nullable error) {
        NSMutableArray *movies = [NSMutableArray array];
        
        if (error == nil) {
            NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
            
            for (NSDictionary *movieDictionary in responseDictionary) {
                id movie = [PCTMovie alloc];
                
                if ([movie conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                    movie = [movie initFromDictionary:movieDictionary];
                    
                    movie == nil ?: [movies addObject:movie];
                }
            }
        }
        
        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
            callback(error, movies);
        }];
    }];
}

+ (NSURLSessionDataTask *)getMovieForImdbID:(NSString *)imdbIdentifier callback:(void (^)(NSError * _Nullable, PCTMovie * _Nullable))callback {
    NSURLSession *session = [NSURLSession sharedSession];
    
    NSURL *URL = [NSURL URLWithString:[NSString stringWithFormat:@"%@/%@", kPCTEndpointMovie, imdbIdentifier]];
    
    return [session dataTaskWithURL:URL completionHandler:^(NSData * _Nullable data,
                                                            NSURLResponse * _Nullable response,
                                                            NSError * _Nullable error) {
        id movie = [PCTMovie alloc];
        
        if (error == nil) {
            NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
            
            if ([movie conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                movie = [movie initFromDictionary:responseDictionary];
            }
        } else {
            movie = nil;
        }
        
        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
            callback(error, movie);
        }];
    }];
}

+ (NSURLSessionDataTask *)getRandomMovieWithCallback:(void (^)(NSError * _Nullable, PCTMovie * _Nullable))callback {
    NSURLSession *session = [NSURLSession sharedSession];
    
    NSURL *URL = [NSURL URLWithString:kPCTEndpointRandomMovie];
    
    return [session dataTaskWithURL:URL completionHandler:^(NSData * _Nullable data,
                                                            NSURLResponse * _Nullable response,
                                                            NSError * _Nullable error) {
        id movie = [PCTMovie alloc];
        
        if (error == nil) {
            NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
            
            if ([movie conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                movie = [movie initFromDictionary:responseDictionary];
            }
        } else {
            movie = nil;
        }
        
        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
            callback(error, movie);
        }];
    }];
}

@end
