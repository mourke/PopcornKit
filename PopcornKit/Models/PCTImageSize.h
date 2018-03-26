//
//  PCTImageSize.h
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

#import <Foundation/NSString.h>

/** The possible sizes a backdrop image can have. */
typedef NSString *PCTBackdropImageSize NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(BackdropImageSize);

/** Width 300px. */
extern PCTBackdropImageSize const PCTBackdropImageSizeSmall;

/** Width 780px. */
extern PCTBackdropImageSize const PCTBackdropImageSizeMedium;

/** Width 1280px. */
extern PCTBackdropImageSize const PCTBackdropImageSizeLarge;

/** The original, uncompressed image. */
extern PCTBackdropImageSize const PCTBackdropImageSizeOriginal;


/** The possible sizes a poster image can have. */
typedef NSString *PCTPosterImageSize NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(PosterImageSize);

/** Width 154px. */
extern PCTPosterImageSize const PCTPosterImageSizeSmall;

/** Width 342px. */
extern PCTPosterImageSize const PCTPosterImageSizeMedium;

/** Width 780px. */
extern PCTPosterImageSize const PCTPosterImageSizeLarge;

/** The original, uncompressed image. */
extern PCTPosterImageSize const PCTPosterImageSizeOriginal;

/** The possible sizes a screenshot image can have. */
typedef NSString *PCTScreenshotImageSize NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(ScreenshotImageSize);

/** Width 92px. */
extern PCTScreenshotImageSize const PCTScreenshotImageSizeSmall;

/** Width 185px. */
extern PCTScreenshotImageSize const PCTScreenshotImageSizeMedium;

/** Width 300px. */
extern PCTScreenshotImageSize const PCTScreenshotImageSizeLarge;

/** The original, uncompressed image. */
extern PCTScreenshotImageSize const PCTScreenshotImageSizeOriginal;
