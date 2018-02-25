//
//  PCTEndpoints.m
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

#import "PCTEndpoints.h"
#import <Foundation/NSString.h>

#define PCT_ENDPOINT_BASE @"https://tv-v2.api-fetch.website"

NSString * const kPCTEndpointMovies = PCT_ENDPOINT_BASE @"/movies";
NSString * const kPCTEndpointMovie = PCT_ENDPOINT_BASE @"/movie";
NSString * const kPCTEndpointRandomMovie = PCT_ENDPOINT_BASE @"/random/movie";

NSString * const kPCTEndpointShows = PCT_ENDPOINT_BASE @"/shows";
NSString * const kPCTEndpointShow = PCT_ENDPOINT_BASE @"/show";
NSString * const kPCTEndpointRandomShow = PCT_ENDPOINT_BASE @"random/show";
