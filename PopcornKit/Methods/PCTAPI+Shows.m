//
//  PCTAPI+Shows.m
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

#import "PCTAPI+Shows.h"
#import "PCTEndpoints.h"
#import "PCTShow.h"
#import "PCTObjectProtocol.h"

@implementation PCTAPI (Shows)

+ (NSURLSessionDataTask *)loadShowsOnPage:(NSUInteger)page
                                   filter:(PCTFilters)filter
                                    genre:(PCTGenres)genre
                              searchQuery:(NSString *)query
                                    order:(PCTOrders)order
                                 callback:(void (^)(NSError * _Nullable, NSArray<PCTPartialShow *> * _Nonnull))callback {
    NSURLSession *session = [NSURLSession sharedSession];
    
    NSURLComponents *components = [NSURLComponents componentsWithString:[NSString stringWithFormat:@"%@/%zx", kPCTEndpointShows, page]];
    
    components.queryItems = @[[NSURLQueryItem queryItemWithName:@"sort" value:filter],
                              [NSURLQueryItem queryItemWithName:@"order" value:@(order).stringValue],
                              [NSURLQueryItem queryItemWithName:@"genre" value:genre],
                              [NSURLQueryItem queryItemWithName:@"keywords" value:query]];
    
    return [session dataTaskWithURL:components.URL completionHandler:^(NSData * _Nullable data,
                                                                       NSURLResponse * _Nullable response,
                                                                       NSError * _Nullable error) {
        NSMutableArray *shows = [NSMutableArray array];
        
        if (error == nil) {
            NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
            
            for (NSDictionary *showDictionary in responseDictionary) {
                id show = [PCTPartialShow alloc];
                
                if ([show conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                    show = [show initFromDictionary:showDictionary];
                    
                    show == nil ?: [shows addObject:show];
                }
            }
        }
        
        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
            callback(error, shows);
        }];
    }];
}

+ (NSURLSessionDataTask *)getShowForImdbID:(NSString *)imdbIdentifier callback:(void (^)(NSError * _Nullable, PCTShow * _Nullable))callback {
    NSURLSession *session = [NSURLSession sharedSession];
    
    NSURL *URL = [NSURL URLWithString:[NSString stringWithFormat:@"%@/%@", kPCTEndpointShow, imdbIdentifier]];
    
    return [session dataTaskWithURL:URL completionHandler:^(NSData * _Nullable data,
                                                            NSURLResponse * _Nullable response,
                                                            NSError * _Nullable error) {
        id show = [PCTShow alloc];
        
        if (error == nil) {
            NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
            
            if ([show conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                show = [show initFromDictionary:responseDictionary];
            }
        } else {
            show = nil;
        }
        
        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
            callback(error, show);
        }];
    }];
}

+ (NSURLSessionDataTask *)getRandomShowWithCallback:(void (^)(NSError * _Nullable, PCTShow * _Nullable))callback {
    NSURLSession *session = [NSURLSession sharedSession];
    
    NSURL *URL = [NSURL URLWithString:kPCTEndpointRandomShow];
    
    return [session dataTaskWithURL:URL completionHandler:^(NSData * _Nullable data,
                                                            NSURLResponse * _Nullable response,
                                                            NSError * _Nullable error) {
        id show = [PCTShow alloc];
        
        if (error == nil) {
            NSDictionary *responseDictionary = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
            
            if ([show conformsToProtocol:@protocol(PCTObjectProtocol)]) {
                show = [show initFromDictionary:responseDictionary];
            }
        } else {
            show = nil;
        }
        
        [[NSOperationQueue mainQueue] addOperationWithBlock:^{
            callback(error, show);
        }];
    }];
}

@end
