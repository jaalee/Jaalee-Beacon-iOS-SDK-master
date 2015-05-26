//
//  JLEConfigBeacon.m
//  Example
//
//  Created by jaalee on 14-4-23.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import "JLEConfigBeacon.h"
#import "JLEReadBeaconParameters.h"
#import "WaitProgressShow.h"
#import "JAALEEBeaconSDK.h"

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
    
    
    if (_mBeaconDevice) {
        [_mBeaconDevice disconnectBeacon];
    }
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

-(void)beaconConfigManager:(JLEBeaconConfigManager *)manager didDiscoverBeacon:(JLEBeaconDevice *)beacon RSSI:(NSNumber *)RSSI AdvData:(NSDictionary *)AdvData
{
    if ([RSSI intValue] > 0 || [RSSI intValue] < -40) {
        return;
    }
    
    if ([_mBeaconDeviceList containsObject:beacon]) {
        [_mBeaconDeviceList removeObject:beacon];
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
    
    JLEBeaconDevice *temp = [_mBeaconDeviceList objectAtIndex:indexPath.row];
    
    name.text = temp.name;
    BeaconID.text = [temp.peripheral.identifier UUIDString];
    rssi.text = [NSString stringWithFormat:@"%ld", (long)temp.rssi];
    
    
    return cell;
    
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView  deselectRowAtIndexPath:indexPath animated:YES];
    _mBeaconDevice = [_mBeaconDeviceList objectAtIndex:indexPath.row];
    if ([_mBeaconDevice isConnectable]) {
        [self performSegueWithIdentifier:@"BeaconMain" sender:nil];
    }
    else
    {
        [WaitProgressShow showErrorWithStatus:@"Current device is in Non-Connectable mode"];
    }

}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString: @"BeaconMain"])
    {
        JLEReadBeaconParameters *ReadParaController = (JLEReadBeaconParameters*) segue.destinationViewController;
        ReadParaController.mSelectBeaconDevice = _mBeaconDevice;
    }
}



@end
