//
//  PopcornKitTests.m
//  PopcornKitTests
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

#import <XCTest/XCTest.h>
#import <PopcornKit/PopcornKit.h>

@interface PopcornKitTests : XCTestCase

@end

@implementation PopcornKitTests

- (void)testMovies {
    XCTestExpectation *expectation = [self expectationWithDescription:@"Load movies"];
    
    [[PCTAPI loadMoviesOnPage:1
                       filter:PCTFiltersTrending
                        genre:PCTGenresAll
                  searchQuery:nil
                        order:PCTOrdersDescending
                     callback:^(NSError * _Nullable error, NSArray<PCTMovie *> * _Nonnull movies) {
                         XCTAssertNil(error, @"Failed to load movies %@", error);
                         XCTAssertFalse(movies.count == 0, @"Results were empty");
                         [expectation fulfill];
    }] resume];
    
    [self waitForExpectationsWithTimeout:5.0 handler:nil];
}

- (void)testShows {
    XCTestExpectation *expectation = [self expectationWithDescription:@"Load shows"];
    
    [[PCTAPI loadShowsOnPage:1
                      filter:PCTFiltersTrending
                       genre:PCTGenresAll
                 searchQuery:nil
                       order:PCTOrdersDescending
                    callback:^(NSError * _Nullable error, NSArray<PCTShow *> * _Nonnull shows) {
                        XCTAssertNil(error, @"Failed to load shows %@", error);
                        XCTAssertFalse(shows.count == 0, @"Results were empty");
                        [expectation fulfill];
                    }] resume];
    
    [self waitForExpectationsWithTimeout:5.0 handler:nil];
}

- (void)testMovie {
    XCTestExpectation *expectation = [self expectationWithDescription:@"Get movie"];
    
    [[PCTAPI getMovieForImdbID:@"tt3501632" callback:^(NSError * _Nullable error, PCTMovie * _Nullable movie) {
        XCTAssertNil(error, @"Failed to load movie %@", error);
        XCTAssertNotNil(movie, @"An error occured parsing the movie");
        [expectation fulfill];
    }] resume];
    
    [self waitForExpectationsWithTimeout:5.0 handler:nil];
}

- (void)testShow {
    XCTestExpectation *expectation = [self expectationWithDescription:@"Get show"];
    
    [[PCTAPI getShowForImdbID:@"tt3205802" callback:^(NSError * _Nullable error, PCTShow * _Nullable show) {
        XCTAssertNil(error, @"Failed to load movie %@", error);
        XCTAssertNotNil(show, @"An error occured parsing the show");
        [expectation fulfill];
    }] resume];
    
    [self waitForExpectationsWithTimeout:5.0 handler:nil];
}

@end
