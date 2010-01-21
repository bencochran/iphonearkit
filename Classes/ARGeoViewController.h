//
//  ARGeoViewController.h
//  ARKitDemo
//
//  Created by Zac White on 8/2/09.
//  Copyright 2009 Zac White. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ARViewController.h"

@interface ARGeoViewController : ARViewController {
	CLLocation *centerLocation;
}

@property (nonatomic, retain) CLLocation *centerLocation;
@property (nonatomic, readonly) NSArray *locations;

//adding locations
- (void)addLocation:(CLLocation *)location withTitle:(NSString *)title;
- (void)addLocation:(CLLocation *)location withTitle:(NSString *)title animated:(BOOL)animated;

//removing locations
- (void)removeLocation:(CLLocation *)location;
- (void)removeLocation:(CLLocation *)location animated:(BOOL)animated;

- (void)removeLocations:(NSArray *)locations;

@end
