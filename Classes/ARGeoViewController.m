//
//  ARGeoViewController.m
//  ARKitDemo
//
//  Created by Zac White on 8/2/09.
//  Copyright 2009 Zac White. All rights reserved.
//

#import "ARGeoViewController.h"

#import "ARGeoCoordinate.h"

@implementation ARGeoViewController

@synthesize centerLocation;

- (void)setCenterLocation:(CLLocation *)newLocation {
	
	@synchronized(self) {
        if (centerLocation != newLocation) {
            [centerLocation release];
            centerLocation = [newLocation retain];
        }
    }
		
	for (ARGeoCoordinate *geoLocation in self.coordinates) {
		if ([geoLocation isKindOfClass:[ARGeoCoordinate class]]) {
			[geoLocation calibrateUsingOrigin:centerLocation];
			
			if (geoLocation.radialDistance > self.maximumScaleDistance) {
				self.maximumScaleDistance = geoLocation.radialDistance;
			}
		}
	}
}

//adding locations
- (void)addLocation:(CLLocation *)location withTitle:(NSString *)title {
	[self addLocation:location withTitle:title animated:NO];
}

- (void)addLocation:(CLLocation *)location withTitle:(NSString *)title animated:(BOOL)animated {
	ARGeoCoordinate *coordinate = [ARGeoCoordinate coordinateWithLocation:location];
	coordinate.title = title;
	[self addCoordinate:coordinate animated:animated];
}


//removing locations
- (void)removeLocation:(CLLocation *)location {
	[self removeLocation:location animated:NO];
}

- (void)removeLocation:(CLLocation *)location animated:(BOOL)animated {
	ARCoordinate *coordinateToRemove = nil;
	
	for (ARGeoCoordinate *coordinate in self.coordinates) {
		if (coordinate.geoLocation == location) {
			coordinateToRemove = coordinate;
		}
	}
	if (coordinateToRemove != nil) {
		[self removeCoordinate:coordinateToRemove animated:animated];
	}
}

- (void)removeLocations:(NSArray *)locations {
	for (CLLocation *location in locations) {
		[self removeLocation:location];
	}
}

- (NSArray *)locations {
	NSMutableArray *locations = [NSMutableArray arrayWithCapacity:self.coordinates.count];
	for (ARGeoCoordinate *coordinate in self.coordinates) {
		if (coordinate.geoLocation != nil) {
			[locations addObject:coordinate.geoLocation];
		}
	}
	
	return locations;
}

@end
