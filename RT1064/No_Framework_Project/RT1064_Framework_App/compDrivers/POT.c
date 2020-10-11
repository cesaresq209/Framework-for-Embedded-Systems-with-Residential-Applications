/*
 * ADC.c
 *
 * Created: 26/09/2020 12:34:02 p. m.
 *  Author: usuario
 */ 

#include "POT.h"

void initPOT()
{
	adc_config_t adcConfigStrcut;
	/*Init GPIO_AD_B1_10 Pin */
	  IOMUXC_SetPinMux(
	      IOMUXC_GPIO_AD_B1_10_GPIO1_IO26,        /* GPIO_AD_B1_11 is configured as GPIO1_IO26 */
	      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
	  IOMUXC_SetPinConfig(
	      IOMUXC_GPIO_AD_B1_10_GPIO1_IO26,        /* GPIO_AD_B1_10 PAD functional properties : */
	      0xB0u);                                 /* Slew Rate Field: Slow Slew Rate
	                                                 Drive Strength Field: R0/6
	                                                 Speed Field: medium(100MHz)
	                                                 Open Drain Enable Field: Open Drain Disabled
	                                                 Pull / Keep Enable Field: Pull/Keeper Disabled
	                                                 Pull / Keep Select Field: Keeper
	                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
	                                                 Hyst. Enable Field: Hysteresis Disabled */
	  /* ADC configuration */
	  adcConfigStrcut.enableOverWrite = false;							/* OverWrite Disable */
	  adcConfigStrcut.enableContinuousConversion = true;				/* Continuous conversion Enable */
	  adcConfigStrcut.enableHighSpeed = false;							/* High Speed disable */
	  adcConfigStrcut.enableLowPower = false;							/* Low Power mode disable */
	  adcConfigStrcut.enableLongSample = false;							/* Longsample Disable */
	  adcConfigStrcut.enableAsynchronousClockOutput = true;				/* Asynchronous Clock Output Enable */
	  adcConfigStrcut.referenceVoltageSource = 0x00;					/* VREFH/VREFL as reference voltage */
	  adcConfigStrcut.samplePeriodMode = kADC_SamplePeriod2or12Clocks;	/* Defining the sample time duration*/
	  adcConfigStrcut.clockSource = kADC_ClockSourceAD;					/* Select Asynchronous clock to generate ADCK. */
	  adcConfigStrcut.clockDriver = kADC_ClockDriver4;					/* Clock divider */
	  adcConfigStrcut.resolution = kADC_Resolution10Bit;				/* 10 Bit resolution */
	  ADC_Init(ADC_BASE, &adcConfigStrcut);

	    adc_sample_period_mode_t samplePeriodMode; /*!< Select the sample period in long sample mode or short mode. */
	    adc_clock_source_t clockSource; /*!< Select the input clock source to generate the internal clock ADCK. */
	    adc_clock_driver_t clockDriver; /*!< Select the divide ratio used by the ADC to generate the internal clock ADCK. */
	    adc_resolution_t resolution;    /*!< Select the ADC resolution mode. */
}

uint32_t getPotValue()
{
	adc_channel_config_t adcChannelConfigStruct;
	/* Configure the user channel and interrupt. */
	adcChannelConfigStruct.channelNumber                        = ADC_POT_CHANNEL;
	adcChannelConfigStruct.enableInterruptOnConversionCompleted = false;

	ADC_SetChannelConfig(ADC_BASE, ADC_CHANNEL_GROUP, &adcChannelConfigStruct);
		while (0U == ADC_GetChannelStatusFlags(ADC_BASE, ADC_CHANNEL_GROUP))
		{
		}
	return ADC_GetChannelConversionValue(ADC_BASE, ADC_CHANNEL_GROUP);
}
