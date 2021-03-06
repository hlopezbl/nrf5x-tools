#ifndef NRF_SOC_H__
#define NRF_SOC_H__ 
#include <stdint.h>
#include <stdbool.h>
#include "nrf_svc.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"
#include "nrf_error_soc.h"
#define SOC_SVC_BASE 0x20
#define NRF_RADIO_NOTIFICATION_INACTIVE_GUARANTEED_TIME_US (62)
#define SOC_ECB_KEY_LENGTH (16)
#define SOC_ECB_CLEARTEXT_LENGTH (16)
#define SOC_ECB_CIPHERTEXT_LENGTH (SOC_ECB_CLEARTEXT_LENGTH)
#define SD_EVT_IRQn (SWI2_IRQn)
#define SD_EVT_IRQHandler (SWI2_IRQHandler)
#define RADIO_NOTIFICATION_IRQn (SWI1_IRQn)
#define RADIO_NOTIFICATION_IRQHandler (SWI1_IRQHandler)
enum NRF_SOC_SVCS
{
  SD_MUTEX_NEW = SOC_SVC_BASE,
  SD_MUTEX_ACQUIRE,
  SD_MUTEX_RELEASE,
  SD_NVIC_ENABLEIRQ,
  SD_NVIC_DISABLEIRQ,
  SD_NVIC_GETPENDINGIRQ,
  SD_NVIC_SETPENDINGIRQ,
  SD_NVIC_CLEARPENDINGIRQ,
  SD_NVIC_SETPRIORITY,
  SD_NVIC_GETPRIORITY,
  SD_NVIC_SYSTEMRESET,
  SD_NVIC_CRITICAL_REGION_ENTER,
  SD_NVIC_CRITICAL_REGION_EXIT,
  SD_RAND_APPLICATION_POOL_CAPACITY,
  SD_RAND_APPLICATION_BYTES_AVAILABLE,
  SD_RAND_APPLICATION_GET_VECTOR,
  SD_POWER_MODE_SET,
  SD_POWER_SYSTEM_OFF,
  SD_POWER_RESET_REASON_GET,
  SD_POWER_RESET_REASON_CLR,
  SD_POWER_POF_ENABLE,
  SD_POWER_POF_THRESHOLD_SET,
  SD_POWER_RAMON_SET,
  SD_POWER_RAMON_CLR,
  SD_POWER_RAMON_GET,
  SD_POWER_GPREGRET_SET,
  SD_POWER_GPREGRET_CLR,
  SD_POWER_GPREGRET_GET,
  SD_POWER_DCDC_MODE_SET,
  SD_APP_EVT_WAIT,
  SD_CLOCK_HFCLK_REQUEST,
  SD_CLOCK_HFCLK_RELEASE,
  SD_CLOCK_HFCLK_IS_RUNNING,
  SD_PPI_CHANNEL_ENABLE_GET,
  SD_PPI_CHANNEL_ENABLE_SET,
  SD_PPI_CHANNEL_ENABLE_CLR,
  SD_PPI_CHANNEL_ASSIGN,
  SD_PPI_GROUP_TASK_ENABLE,
  SD_PPI_GROUP_TASK_DISABLE,
  SD_PPI_GROUP_ASSIGN,
  SD_PPI_GROUP_GET,
  SD_RADIO_NOTIFICATION_CFG_SET,
  SD_ECB_BLOCK_ENCRYPT,
  SD_RESERVED1,
  SD_RESERVED2,
  SD_RESERVED3,
  SD_EVT_GET,
  SD_TEMP_GET,
  SD_FLASH_ERASE_PAGE,
  SD_FLASH_WRITE,
  SD_FLASH_PROTECT,
  SVC_SOC_LAST
};
enum NRF_MUTEX_VALUES
{
  NRF_MUTEX_FREE,
  NRF_MUTEX_TAKEN
};
enum NRF_APP_PRIORITIES
{
  NRF_APP_PRIORITY_HIGH = 1,
  NRF_APP_PRIORITY_LOW = 3
};
enum NRF_POWER_MODES
{
  NRF_POWER_MODE_CONSTLAT,
  NRF_POWER_MODE_LOWPWR
};
enum NRF_POWER_THRESHOLDS
{
  NRF_POWER_THRESHOLD_V21,
  NRF_POWER_THRESHOLD_V23,
  NRF_POWER_THRESHOLD_V25,
  NRF_POWER_THRESHOLD_V27
};
enum NRF_POWER_DCDC_MODES
{
  NRF_POWER_DCDC_MODE_OFF,
  NRF_POWER_DCDC_MODE_ON,
  NRF_POWER_DCDC_MODE_AUTOMATIC
};
enum NRF_RADIO_NOTIFICATION_DISTANCES
{
  NRF_RADIO_NOTIFICATION_DISTANCE_NONE = 0,
  NRF_RADIO_NOTIFICATION_DISTANCE_800US,
  NRF_RADIO_NOTIFICATION_DISTANCE_1740US,
  NRF_RADIO_NOTIFICATION_DISTANCE_2680US,
  NRF_RADIO_NOTIFICATION_DISTANCE_3620US,
  NRF_RADIO_NOTIFICATION_DISTANCE_4560US,
  NRF_RADIO_NOTIFICATION_DISTANCE_5500US
};
enum NRF_RADIO_NOTIFICATION_TYPES
{
  NRF_RADIO_NOTIFICATION_TYPE_NONE = 0,
  NRF_RADIO_NOTIFICATION_TYPE_INT_ON_ACTIVE,
  NRF_RADIO_NOTIFICATION_TYPE_INT_ON_INACTIVE,
  NRF_RADIO_NOTIFICATION_TYPE_INT_ON_BOTH,
};
enum NRF_SOC_EVTS
{
  NRF_EVT_HFCLKSTARTED,
  NRF_EVT_POWER_FAILURE_WARNING,
  NRF_EVT_FLASH_OPERATION_SUCCESS,
  NRF_EVT_FLASH_OPERATION_ERROR,
  NRF_EVT_RESERVED1,
  NRF_EVT_RESERVED2,
  NRF_EVT_RESERVED3,
  NRF_EVT_RESERVED4,
  NRF_EVT_RESERVED5,
  NRF_EVT_NUMBER_OF_EVTS
};
typedef volatile uint8_t nrf_mutex_t;
typedef uint8_t nrf_app_irq_priority_t;
typedef uint8_t nrf_power_mode_t;
typedef uint8_t nrf_power_failure_threshold_t;
typedef uint32_t nrf_power_dcdc_mode_t;
typedef uint8_t nrf_radio_notification_distance_t;
typedef uint8_t nrf_radio_notification_type_t;
typedef struct
{
  uint8_t key[SOC_ECB_KEY_LENGTH];
  uint8_t cleartext[SOC_ECB_CLEARTEXT_LENGTH];
  uint8_t ciphertext[SOC_ECB_CIPHERTEXT_LENGTH];
} nrf_ecb_hal_data_t;
SVCALL(SD_MUTEX_NEW, uint32_t, sd_mutex_new(nrf_mutex_t * p_mutex));
SVCALL(SD_MUTEX_ACQUIRE, uint32_t, sd_mutex_acquire(nrf_mutex_t * p_mutex));
SVCALL(SD_MUTEX_RELEASE, uint32_t, sd_mutex_release(nrf_mutex_t * p_mutex));
SVCALL(SD_NVIC_ENABLEIRQ, uint32_t, sd_nvic_EnableIRQ(IRQn_Type IRQn));
SVCALL(SD_NVIC_DISABLEIRQ, uint32_t, sd_nvic_DisableIRQ(IRQn_Type IRQn));
SVCALL(SD_NVIC_GETPENDINGIRQ, uint32_t, sd_nvic_GetPendingIRQ(IRQn_Type IRQn, uint32_t * p_pending_irq));
SVCALL(SD_NVIC_SETPENDINGIRQ, uint32_t, sd_nvic_SetPendingIRQ(IRQn_Type IRQn));
SVCALL(SD_NVIC_CLEARPENDINGIRQ, uint32_t, sd_nvic_ClearPendingIRQ(IRQn_Type IRQn));
SVCALL(SD_NVIC_SETPRIORITY, uint32_t, sd_nvic_SetPriority(IRQn_Type IRQn, nrf_app_irq_priority_t priority));
SVCALL(SD_NVIC_GETPRIORITY, uint32_t, sd_nvic_GetPriority(IRQn_Type IRQn, nrf_app_irq_priority_t * p_priority));
SVCALL(SD_NVIC_SYSTEMRESET, uint32_t, sd_nvic_SystemReset(void));
SVCALL(SD_NVIC_CRITICAL_REGION_ENTER, uint32_t, sd_nvic_critical_region_enter(uint8_t * p_is_nested_critical_region));
SVCALL(SD_NVIC_CRITICAL_REGION_EXIT, uint32_t, sd_nvic_critical_region_exit(uint8_t is_nested_critical_region));
SVCALL(SD_RAND_APPLICATION_POOL_CAPACITY, uint32_t, sd_rand_application_pool_capacity_get(uint8_t * p_pool_capacity));
SVCALL(SD_RAND_APPLICATION_BYTES_AVAILABLE, uint32_t, sd_rand_application_bytes_available_get(uint8_t * p_bytes_available));
SVCALL(SD_RAND_APPLICATION_GET_VECTOR, uint32_t, sd_rand_application_vector_get(uint8_t * p_buff, uint8_t length));
SVCALL(SD_POWER_RESET_REASON_GET, uint32_t, sd_power_reset_reason_get(uint32_t * p_reset_reason));
SVCALL(SD_POWER_RESET_REASON_CLR, uint32_t, sd_power_reset_reason_clr(uint32_t reset_reason_clr_msk));
SVCALL(SD_POWER_MODE_SET, uint32_t, sd_power_mode_set(nrf_power_mode_t power_mode));
SVCALL(SD_POWER_SYSTEM_OFF, uint32_t, sd_power_system_off(void));
SVCALL(SD_POWER_POF_ENABLE, uint32_t, sd_power_pof_enable(uint8_t pof_enable));
SVCALL(SD_POWER_POF_THRESHOLD_SET, uint32_t, sd_power_pof_threshold_set(nrf_power_failure_threshold_t threshold));
SVCALL(SD_POWER_RAMON_SET, uint32_t, sd_power_ramon_set(uint32_t ramon));
SVCALL(SD_POWER_RAMON_CLR, uint32_t, sd_power_ramon_clr(uint32_t ramon));
SVCALL(SD_POWER_RAMON_GET, uint32_t, sd_power_ramon_get(uint32_t * p_ramon));
SVCALL(SD_POWER_GPREGRET_SET, uint32_t, sd_power_gpregret_set(uint32_t gpregret_msk));
SVCALL(SD_POWER_GPREGRET_CLR, uint32_t, sd_power_gpregret_clr(uint32_t gpregret_msk));
SVCALL(SD_POWER_GPREGRET_GET, uint32_t, sd_power_gpregret_get(uint32_t *p_gpregret));
SVCALL(SD_POWER_DCDC_MODE_SET, uint32_t, sd_power_dcdc_mode_set(nrf_power_dcdc_mode_t dcdc_mode));
SVCALL(SD_CLOCK_HFCLK_REQUEST, uint32_t, sd_clock_hfclk_request(void));
SVCALL(SD_CLOCK_HFCLK_RELEASE, uint32_t, sd_clock_hfclk_release(void));
SVCALL(SD_CLOCK_HFCLK_IS_RUNNING, uint32_t, sd_clock_hfclk_is_running(uint32_t * p_is_running));
SVCALL(SD_APP_EVT_WAIT, uint32_t, sd_app_evt_wait(void));
SVCALL(SD_PPI_CHANNEL_ENABLE_GET, uint32_t, sd_ppi_channel_enable_get(uint32_t * p_channel_enable));
SVCALL(SD_PPI_CHANNEL_ENABLE_SET, uint32_t, sd_ppi_channel_enable_set(uint32_t channel_enable_set_msk));
SVCALL(SD_PPI_CHANNEL_ENABLE_CLR, uint32_t, sd_ppi_channel_enable_clr(uint32_t channel_enable_clr_msk));
SVCALL(SD_PPI_CHANNEL_ASSIGN, uint32_t, sd_ppi_channel_assign(uint8_t channel_num, const volatile void * evt_endpoint, const volatile void * task_endpoint));
SVCALL(SD_PPI_GROUP_TASK_ENABLE, uint32_t, sd_ppi_group_task_enable(uint8_t group_num));
SVCALL(SD_PPI_GROUP_TASK_DISABLE, uint32_t, sd_ppi_group_task_disable(uint8_t group_num));
SVCALL(SD_PPI_GROUP_ASSIGN, uint32_t, sd_ppi_group_assign(uint8_t group_num, uint32_t channel_msk));
SVCALL(SD_PPI_GROUP_GET, uint32_t, sd_ppi_group_get(uint8_t group_num, uint32_t * p_channel_msk));
SVCALL(SD_RADIO_NOTIFICATION_CFG_SET, uint32_t, sd_radio_notification_cfg_set(nrf_radio_notification_type_t type, nrf_radio_notification_distance_t distance));
SVCALL(SD_ECB_BLOCK_ENCRYPT, uint32_t, sd_ecb_block_encrypt(nrf_ecb_hal_data_t * p_ecb_data));
SVCALL(SD_EVT_GET, uint32_t, sd_evt_get(uint32_t * p_evt_id));
SVCALL(SD_TEMP_GET, uint32_t, sd_temp_get(int32_t * p_temp));
SVCALL(SD_FLASH_WRITE, uint32_t, sd_flash_write(uint32_t * const p_dst, uint32_t const * const p_src, uint32_t size));
SVCALL(SD_FLASH_ERASE_PAGE, uint32_t, sd_flash_page_erase(uint32_t page_number));
SVCALL(SD_FLASH_PROTECT, uint32_t, sd_flash_protect(uint32_t protenset0, uint32_t protenset1));
#endif
