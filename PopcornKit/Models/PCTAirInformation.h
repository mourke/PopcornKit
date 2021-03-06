//
//  PCTAirInformation.h
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
#import "PCTAirStatus.h"

NS_ASSUME_NONNULL_BEGIN

/**
 General air information that every episode in the series follows.
 */
NS_SWIFT_NAME(AirInformation)
@interface PCTAirInformation : NSObject

/** Airing status for a show (ended or returning). */
@property (strong, nonatomic, readonly) PCTAirStatus status;

/** Date components describing the time at which and the day on which the show is aired. If the show has ended, all of these components will be `nil`. */
@property (strong, nonatomic, readonly) NSDateComponents *dateComponents;

/** The ISO 3166-2 code for the country in which the show is set/recorded. */
@property (strong, nonatomic, readonly) NSString *countryCode;

/** The original network on which the show is released. */
@property (strong, nonatomic, readonly) NSString *network;

@end

NS_ASSUME_NONNULL_END
