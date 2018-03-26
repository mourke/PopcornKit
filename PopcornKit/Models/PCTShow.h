//
//  PCTShow.h
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
#import "PCTPartialShow.h"

@class PCTSeason, PCTAirInformation;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Show)
@interface PCTShow : PCTPartialShow

/** A short summary of the show's plot. */
@property (strong, nonatomic, readonly) NSString *synopsis;

/** The length of each episode (in minutes). */
@property (nonatomic, readonly) NSInteger runtime;

/** Information about the show's airings. */
@property (strong, nonatomic, readonly) PCTAirInformation *airInformation;

/** The genres that the show is a type of. */
@property (strong, nonatomic, readonly) NSArray<NSString *> *genres;

/** The episodes in the show. */
@property (strong, nonatomic, readonly) NSArray<PCTSeason *> *seasons;


@end

NS_ASSUME_NONNULL_END
