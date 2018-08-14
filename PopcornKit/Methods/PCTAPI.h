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

typedef NS_ENUM(NSInteger, PCTOrder) {
    PCTOrderAscending = 1,
    PCTOrderDescending = -1
} NS_SWIFT_NAME(Order);

/**
 The values used to filter down a response from the api.
 */
typedef NSString *PCTFilter NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(Filter);

/** An A-Z (or Z-A depending on the `PCTOrder` value) list of all movies. */
extern PCTFilter const PCTFilterAlphabetically;

/** A list of currently trending movies. */
extern PCTFilter const PCTFilterTrending;

/** A list of movies sorted by their IMDB rating. */
extern PCTFilter const PCTFilterRating;

/** A list of movies that were recently added to the api. */
extern PCTFilter const PCTFilterDate;

/** A list of the newest movies on the api. */
extern PCTFilter const PCTFilterYear;


/**
 The different possible genres that a movie can fall into.
 */
typedef NSString *PCTGenre NS_EXTENSIBLE_STRING_ENUM NS_SWIFT_NAME(Genre);

extern PCTGenre const PCTGenreAll;
extern PCTGenre const PCTGenreAction;
extern PCTGenre const PCTGenreAdventure;
extern PCTGenre const PCTGenreAnimation;
extern PCTGenre const PCTGenreComedy;
extern PCTGenre const PCTGenreCrime;
extern PCTGenre const PCTGenreDisaster;
extern PCTGenre const PCTGenreDocumentary;
extern PCTGenre const PCTGenreDrama;
extern PCTGenre const PCTGenreFamily;
extern PCTGenre const PCTGenreFanFilm;
extern PCTGenre const PCTGenreFantasy;
extern PCTGenre const PCTGenreFilmNoir;
extern PCTGenre const PCTGenreHistory;
extern PCTGenre const PCTGenreHoliday;
extern PCTGenre const PCTGenreHorror;
extern PCTGenre const PCTGenreIndie;
extern PCTGenre const PCTGenreMusic;
extern PCTGenre const PCTGenreMystery;
extern PCTGenre const PCTGenreRoad;
extern PCTGenre const PCTGenreRomance;
extern PCTGenre const PCTGenreScienceFiction;
extern PCTGenre const PCTGenreShort;
extern PCTGenre const PCTGenreSports;
extern PCTGenre const PCTGenreSportingEvent;
extern PCTGenre const PCTGenreSuspense;
extern PCTGenre const PCTGenreThriller;
extern PCTGenre const PCTGenreWar;
extern PCTGenre const PCTGenreWestern;

@end
