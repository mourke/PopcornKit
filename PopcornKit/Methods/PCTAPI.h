//
//  PCTAPI.h
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

NS_SWIFT_NAME(PopcornKit)
@interface PCTAPI : NSObject

NS_SWIFT_NAME(Orders)
typedef NS_ENUM(NSInteger, PCTOrders) {
    PCTOrdersAscending = 1,
    PCTOrdersDescending = -1
};

/**
 The values used to filter down a response from the api.
 */
typedef NSString *PCTFilters NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(Filters);

/** An A-Z (or Z-A depending on the `PCTOrders` value) list of all movies. */
extern PCTFilters const PCTFiltersAlphabetically;

/** A list of currently trending movies. */
extern PCTFilters const PCTFiltersTrending;

/** A list of movies sorted by their IMDB rating. */
extern PCTFilters const PCTFiltersRating;

/** A list of movies that were recently added to the api. */
extern PCTFilters const PCTFiltersDate;

/** A list of the newest movies on the api. */
extern PCTFilters const PCTFiltersYear;


/**
 The different possible genres that a movie can fall into.
 */
typedef NSString *PCTGenres NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(Genres);

extern PCTGenres const PCTGenresAll;
extern PCTGenres const PCTGenresAction;
extern PCTGenres const PCTGenresAdventure;
extern PCTGenres const PCTGenresAnimation;
extern PCTGenres const PCTGenresComedy;
extern PCTGenres const PCTGenresCrime;
extern PCTGenres const PCTGenresDisaster;
extern PCTGenres const PCTGenresDocumentary;
extern PCTGenres const PCTGenresDrama;
extern PCTGenres const PCTGenresFamily;
extern PCTGenres const PCTGenresFanFilm;
extern PCTGenres const PCTGenresFantasy;
extern PCTGenres const PCTGenresFilmNoir;
extern PCTGenres const PCTGenresHistory;
extern PCTGenres const PCTGenresHoliday;
extern PCTGenres const PCTGenresHorror;
extern PCTGenres const PCTGenresIndie;
extern PCTGenres const PCTGenresMusic;
extern PCTGenres const PCTGenresMystery;
extern PCTGenres const PCTGenresRoad;
extern PCTGenres const PCTGenresRomance;
extern PCTGenres const PCTGenresScienceFiction;
extern PCTGenres const PCTGenresShort;
extern PCTGenres const PCTGenresSports;
extern PCTGenres const PCTGenresSportingEvent;
extern PCTGenres const PCTGenresSuspense;
extern PCTGenres const PCTGenresThriller;
extern PCTGenres const PCTGenresWar;
extern PCTGenres const PCTGenresWestern;

@end
