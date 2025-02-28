    #include "gdt.h"
    #include "../screen/screen.h"
     // #include "isr.h"
    // #include "idt.h"

    // Lets us call init_gdt in cpp and init_gdt in assembly
    void init_gdt() asm ("init_gdt");

    extern "C" {
        // Lets us access our ASM functions from our C code.
        extern void gdt_flush(uint32_t);
        static void gdt_set_gate(int32_t,uint32_t,uint32_t,uint8_t,uint8_t);

    }

    UiAOS::CPU::GDT::gdt_entry_t gdt_entries[6];
    UiAOS::CPU::GDT::gdt_ptr_t   gdt_ptr;

    void init_gdt()
    {
         write_string('15', "Hello JON");
        gdt_ptr.limit = (sizeof(UiAOS::CPU::GDT::gdt_entry_t) * 6) - 1;
        gdt_ptr.base  = (uint32_t)&gdt_entries;

        gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
        gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
        gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment

        gdt_flush((uint32_t)&gdt_ptr);
    }



    // Set the value of one GDT entry.
    void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
    {
        gdt_entries[num].base_low    = (base & 0xFFFF);
        gdt_entries[num].base_middle = (base >> 16) & 0xFF;
        gdt_entries[num].base_high   = (base >> 24) & 0xFF;

        gdt_entries[num].limit_low   = (limit & 0xFFFF);
        gdt_entries[num].granularity = (limit >> 16) & 0x0F;

        gdt_entries[num].granularity |= gran & 0xF0;
        gdt_entries[num].access      = access;
    }

