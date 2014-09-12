//
//  JLEConfigBeacon.m
//  Example
//
//  Created by jaalee on 14-4-23.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import "JLEConfigBeacon.h"
#import "JLEBeaconDevice.h"
#import "JLEReadBeaconParameters.h"
#import "JLEWaitProgressShow.h"

@interface JLEConfigBeacon ()

@property (nonatomic)        NSMutableArray *mBeaconDeviceList;
@property (nonatomic)        JLEBeaconConfigManager *mBeaconConfigManager;
@property (nonatomic)        JLEBeaconDevice *mBeaconDevice;

@end

@implementation JLEConfigBeacon

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
    
    _mBeaconDeviceList = [[NSMutableArray alloc] init];
    _mBeaconConfigManager = [[JLEBeaconConfigManager alloc] init];
    _mBeaconConfigManager.delegate = self;
}


-(void)viewDidAppear:(BOOL)animated
{
    [_mBeaconDeviceList removeAllObjects];
    [self.mTableView reloadData];
    [_mBeaconConfigManager startJaaleeBeaconsDiscovery];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

#pragma mark - JLEBeaconConfigManager delegate

- (void)beaconConfigManager:(JLEBeaconConfigManager *)manager didDiscoverBeacon:(JLEBeaconDevice *)beacon RSSI:(NSNumber *)RSSI
{
    
    for (int i = 0; i < _mBeaconDeviceList.count; i++) {
        JLEBeaconDevice *temp = [_mBeaconDeviceList objectAtIndex:i];
        if (temp == beacon) {
            return;
        }
    }
    
    [_mBeaconDeviceList addObject:beacon];
    [self.mTableView reloadData];
}



#pragma mark - Table view data source

-(NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section
{
	return _mBeaconDeviceList.count;
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
    UILabel *connectable = (UILabel*)[cell viewWithTag:4];
    
    JLEBeaconDevice *temp = [_mBeaconDeviceList objectAtIndex:indexPath.row];
    
    name.text = temp.name;
    BeaconID.text = [temp.peripheral.identifier UUIDString];
    rssi.text = [NSString stringWithFormat:@"%d", temp.rssi];
    if (temp.isConnectable) {
        [connectable setText:@"true"];
    }
    else
    {
        [connectable setText:@"false"];
    }
    
    
    return cell;
    
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView  deselectRowAtIndexPath:indexPath animated:YES];
    _mBeaconDevice = [_mBeaconDeviceList objectAtIndex:indexPath.row];
    
    if (_mBeaconDevice.isConnectable) {
        [self performSegueWithIdentifier:@"ConfigDetail" sender:nil];
    }
    else
    {
        [JLEWaitProgressShow showErrorWithStatus:@"Current device is in Non-Connectable mode"];
    }
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString: @"ConfigDetail"])
    {
        JLEReadBeaconParameters *ReadParaController = (JLEReadBeaconParameters*) segue.destinationViewController;
        ReadParaController.mSelectBeaconDevice = _mBeaconDevice;
    }
}



@end
