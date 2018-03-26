//
//  PCTCertification.h
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
 The Motion Picture Association of America rating system for movies.
 */
typedef NSString *PCTMovieCertification NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(MovieCertification);

/** All ages admitted. Nothing that would offend parents for viewing by children. */
extern PCTMovieCertification const PCTMovieCertificationG;

/** Some material may not be suitable for children. Parents urged to give "parental guidance". May contain some material parents might not like for their young children. */
extern PCTMovieCertification const PCTMovieCertificationPG;

/** Some material may be inappropriate for children under 13. Parents are urged to be cautious. Some material may be inappropriate for pre-teenagers. */
extern PCTMovieCertification const PCTMovieCertificationPG13;

/** Under 17 requires accompanying parent or adult guardian. Contains some adult material. Parents are urged to learn more about the film before taking their young children with them. */
extern PCTMovieCertification const PCTMovieCertificationR;

/** No One 17 and Under Admitted. Clearly adult. Children are not admitted. */
extern PCTMovieCertification const PCTMovieCertificationNC17;


/**
 A TV Show rating system devised by the National Cable & Telecommunications Association, and the Motion Picture Association of America.
 */
typedef NSString *PCTTVCertification NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(TVCertification);

/** This program is designed to be appropriate for all children. */
extern PCTTVCertification const PCTTVCertificationY;

/** This program is designed for children age 7 and above.*/
extern PCTTVCertification const PCTTVCertification7Y;

/** Programs suitable for all ages. */
extern PCTTVCertification const PCTTVCertificationG;

/** This program contains material that parents may find unsuitable for younger children. */
extern PCTTVCertification const PCTTVCertificationPG;

/** This program contains some material that many parents would find unsuitable for children under 14 years of age. */
extern PCTTVCertification const PCTTVCertification14;

/** This program is specifically designed to be viewed by adults and therefore may be unsuitable for children under 17. */
extern PCTTVCertification const PCTTVCertificationMA;

