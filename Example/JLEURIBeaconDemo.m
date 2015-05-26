//
//  JLEURIBeaconDemo.m
//  Example
//
//  Created by jaalee on 15/5/19.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import "JLEURIBeaconDemo.h"
#import "JAALEEBeaconSDK.h"

@interface JLEURIBeaconDemo ()<JLEURIBeaconManagerDelegate>

@property (nonatomic)        NSMutableArray *mUriBeaconDeviceList;
@property (nonatomic)        JLEURIBeaconManager *mURIBeaconManager;

@end

@implementation JLEURIBeaconDemo


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    _mUriBeaconDeviceList = [[NSMutableArray alloc] init];
    _mURIBeaconManager = [[JLEURIBeaconManager alloc] init];
    _mURIBeaconManager.delegate = self;
}

-(void) viewWillAppear:(BOOL)animated
{
    [_mUriBeaconDeviceList removeAllObjects];
    [self.mTableView reloadData];
    [_mURIBeaconManager startScanURIBeaconAround];    
}

 -(void)viewWillDisappear:(BOOL)animated
{
    [_mURIBeaconManager stopScanURIBeacon];
}

- (void)URIBeaconManager:(JLEURIBeaconManager *)manager didFoundURIBeacons:(NSArray *)beacons
{
    for (JLEURIBeacon *UriBeacon in beacons)
    {
        if ([_mUriBeaconDeviceList containsObject:UriBeacon]) {
            [_mUriBeaconDeviceList removeObject:UriBeacon];
        }
        [_mUriBeaconDeviceList addObject:UriBeacon];
    }
    
    [self.mTableView reloadData];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - Table view data source

-(NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section
{
    return _mUriBeaconDeviceList.count;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView;
{
    return 1;
}


- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    return @"Scanning...";
}


- (UITableViewCell *)tableView:(UITableView *)tv cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell;
    
    cell = [tv dequeueReusableCellWithIdentifier:@"BeaconDeviceCell"];
    
    UILabel *name = (UILabel*)[cell viewWithTag:1];
    UILabel *BeaconID = (UILabel*)[cell viewWithTag:2];
    UILabel *rssi = (UILabel*)[cell viewWithTag:3];
    
    JLEURIBeacon *temp = [_mUriBeaconDeviceList objectAtIndex:indexPath.row];
    
    NSLog(@"URL:%@", [[temp URI] absoluteString]);
    name.text = [[temp URI] absoluteString];
    BeaconID.text = [temp.identifier UUIDString];
    rssi.text = [NSString stringWithFormat:@"%ld", (long)temp.RSSI];    
    
    return cell;
    
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView  deselectRowAtIndexPath:indexPath animated:YES];
    
    JLEURIBeacon *temp = [_mUriBeaconDeviceList objectAtIndex:indexPath.row];
    
    [[UIApplication sharedApplication] openURL:temp.URI];
//    _mBeaconDevice = [_mBeaconDeviceList objectAtIndex:indexPath.row];
//    [self performSegueWithIdentifier:@"ConfigDetail" sender:nil];
}

//- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
//{
//    if ([segue.identifier isEqualToString: @"ConfigDetail"])
//    {
//        JLEReadBeaconParameters *ReadParaController = (JLEReadBeaconParameters*) segue.destinationViewController;
//        ReadParaController.mSelectBeaconDevice = _mBeaconDevice;
//    }
//}

@end
