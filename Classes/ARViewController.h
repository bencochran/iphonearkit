//
//  ARKViewController.h
//  ARKitDemo
//
//  Created by Zac White on 8/1/09.
//  Copyright 2009 Zac White. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CoreLocation/CoreLocation.h>

#import "ARCoordinate.h"

@protocol ARViewDelegate

- (UIView *)viewForCoordinate:(ARCoordinate *)coordinate;

@optional
- (BOOL)shouldAutorotateViewsToInterfaceOrientation:(UIInterfaceOrientation)possibleOrientation;

@end


@interface ARViewController : UIViewController <UIAccelerometerDelegate, CLLocationManagerDelegate> {
	CLLocationManager *locationManager;
	UIAccelerometer *accelerometerManager;
	
	ARCoordinate *centerCoordinate;
	
	UIImagePickerController *cameraController;
	
	NSObject<ARViewDelegate> *delegate;
	NSObject<CLLocationManagerDelegate> *locationDelegate;
	NSObject<UIAccelerometerDelegate> *accelerometerDelegate;
	
	BOOL scaleViewsBasedOnDistance;
	double maximumScaleDistance;
	double minimumScaleFactor;
	
	BOOL rotateViewsBasedOnPerspective;
	double maximumRotationAngle;

@private
	double _latestHeading;
	UIAccelerationValue _latestXAcceleration;
	UIAccelerationValue _latestYAcceleration;
	UIAccelerationValue _latestZAcceleration;
	
	//in radians.
	double _viewportRotation;
	
	BOOL ar_debugMode;
	
	UIView *ar_overlayView;
	
	UILabel *ar_debugView;
	
	NSMutableArray *ar_coordinates;
	NSMutableArray *ar_coordinateViews;
}

@property (readonly) NSArray *coordinates;

@property BOOL debugMode;

@property BOOL scaleViewsBasedOnDistance;
@property double maximumScaleDistance;
@property double minimumScaleFactor;

@property BOOL rotateViewsBasedOnPerspective;
@property double maximumRotationAngle;

//adding coordinates to the underlying data model.
- (void)addCoordinate:(ARCoordinate *)coordinate;
- (void)addCoordinate:(ARCoordinate *)coordinate animated:(BOOL)animated;

- (void)addCoordinates:(NSArray *)newCoordinates;

- (void)clearCoordinates;
- (void)replaceCoordinates:(NSArray *)newCoordinates;

//removing coordinates
- (void)removeCoordinate:(ARCoordinate *)coordinate;
- (void)removeCoordinate:(ARCoordinate *)coordinate animated:(BOOL)animated;

- (void)removeCoordinates:(NSArray *)coordinates;

- (id)initWithLocationManager:(CLLocationManager *)manager;
- (id)initWithLocationManager:(CLLocationManager *)manager accelerometer:(UIAccelerometer *)accelerometer;

- (void)startListening;
- (void)updateLocations:(NSTimer *)timer;

- (CGPoint)pointInView:(UIView *)realityView withView:(UIView *)viewToDraw forCoordinate:(ARCoordinate *)coordinate;

- (BOOL)viewportContainsView:(UIView *)viewToDraw forCoordinate:(ARCoordinate *)coordinate;

@property (nonatomic, retain) UIImagePickerController *cameraController;

@property (nonatomic, assign) NSObject<ARViewDelegate> *delegate;
@property (nonatomic, assign) NSObject<CLLocationManagerDelegate> *locationDelegate;
@property (nonatomic, assign) NSObject<UIAccelerometerDelegate> *accelerometerDelegate;

@property (retain) ARCoordinate *centerCoordinate;

@property (nonatomic, retain) UIAccelerometer *accelerometerManager;
@property (nonatomic, retain) CLLocationManager *locationManager;

@end
