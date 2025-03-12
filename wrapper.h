#include <stdint.h>

// Note: this module assume
//  1. template uses #size-cells = <0x2> and #address-cells = <0x2>
//  2. `chosen` node exists

struct region {
  uint64_t ipa_start;
  uint64_t length;
};

int fdt_remove_node(void *fdt, const char *path);

int fdt_disable_node(void *fdt, const char *path);

void fdt_add_virtio(void *fdt, const char *name, uint32_t spi_irq,
                    uint64_t address);

void fdt_add_vm_service(void *fdt, uint32_t spi_irq, uint64_t address,
                        uint64_t len);

void fdt_add_timer(void *fdt, uint32_t trigger_lvl);

void fdt_add_vm_service_blk(void *fdt, uint32_t spi_irq);

void fdt_add_cpu(void *fdt, uint64_t linear_id, uint8_t core_id,
                 uint8_t cluster_id, const char *compatible);

void fdt_set_bootcmd(void *fdt, const char *cmdline);

void fdt_set_initrd(void *fdt, uint32_t start, uint32_t end);

void fdt_set_memory(void *fdt, uint64_t region_num,
                    const struct region *regions, const char *node_name);

void fdt_clear_initrd(void *fdt);

int fdt_setup_gic(void *fdt, uint64_t gicd_addr, uint64_t gicc_addr,
                  const char *node_name);

void fdt_setup_serial(void *fdt, const char *compatible, uint64_t addr,
                      uint32_t spi_irq);

void fdt_set_stdout_path(void *fdt, const char *p);

void fdt_clear_stdout_path(void *fdt);

int fdt_create_node(void *fdt, const char *path, const char *name);

int fdt_add_property_string(void *fdt, int node, const char *name, const char *str);

int fdt_add_property_u32(void *fdt, int node, const char *name, uint32_t val);

int fdt_add_property_u64_array(void *fdt, int node, const char *name, uint64_t *values, int len);

int fdt_add_property_u32_array(void *fdt, int node, const char *name, uint32_t *values, int len);

void fdt_enlarge(void *fdt);

uint64_t fdt_size(void *fdt);

int fdt_pack(void *fdt);

int fdt_del_mem_rsv(void *fdt, int n);

int fdt_setup_pmu(void *fdt, const char *compatible, const uint32_t *spi_irq,
                  uint32_t spi_irq_len, const uint32_t *irq_affi,
                  uint32_t irq_affi_len);

int fdt_overlay_apply(void *fdt, void *fdto);

int fdt_open_into(const void *fdt, void *buf, int bufsize);

/**
 * fdt_get_property_string - Get a string property from a node
 * @fdt: pointer to the device tree blob
 * @path: path to the node
 * @prop: property name
 * @len: length of the target string, assigned by the function
 */
char* fdt_get_property_string(void *fdt, const char *path, const char *prop, int *len);

int fdt_find_node(void *fdt, const char *path);

int fdt_setprop_raw(void *fdt, int nodeoffset, const char *name,
  const void *val, int len);
