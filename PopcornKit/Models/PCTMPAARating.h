//
//  PCTMPAARating.h
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

/**
 The Motion Picture Association of America rating system.
 */
typedef NSString *PCTMPAARating NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(MPAARating);

/** All ages admitted. Nothing that would offend parents for viewing by children. */
extern PCTMPAARating const PCTMPAARatingG;

/** Some material may not be suitable for children. Parents urged to give "parental guidance". May contain some material parents might not like for their young children. */
extern PCTMPAARating const PCTMPAARatingPG;

/** Some material may be inappropriate for children under 13. Parents are urged to be cautious. Some material may be inappropriate for pre-teenagers. */
extern PCTMPAARating const PCTMPAARatingPG13;

/** Under 17 requires accompanying parent or adult guardian. Contains some adult material. Parents are urged to learn more about the film before taking their young children with them. */
extern PCTMPAARating const PCTMPAARatingR;

/** No One 17 and Under Admitted. Clearly adult. Children are not admitted. */
extern PCTMPAARating const PCTMPAARatingNC17;
