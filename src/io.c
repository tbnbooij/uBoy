#include "io.h"

void IO_init(void) {
    IO_Registers.TIMA = 0;
    IO_Registers.TMA = 0;
    IO_Registers.TAC = 0;
    IO_Registers.NR10 = 0x80;
    IO_Registers.NR11 = 0xBF;
    IO_Registers.NR12 = 0xF3;
    IO_Registers.NR14 = 0xBF;
    IO_Registers.NR21 = 0x3F;
    IO_Registers.NR22 = 0;
    IO_Registers.NR24 = 0xBF;
    IO_Registers.NR30 = 0x7F;
    IO_Registers.NR31 = 0xFF;
    IO_Registers.NR32 = 0x9F;
    IO_Registers.NR33 = 0xBF;
    IO_Registers.NR41 = 0xFF;
    IO_Registers.NR42 = 0;
    IO_Registers.NR43 = 0;
    IO_Registers.NR44 = 0xBF;
    IO_Registers.NR50 = 0x77;
    IO_Registers.NR51 = 0xF3;
    IO_Registers.NR52 = 0xF1;
    IO_Registers.LCDC = 0x91;
    IO_Registers.SCY = 0;
    IO_Registers.SCX = 0;
    IO_Registers.LYC = 0;
    IO_Registers.BGP = 0xFC;
    IO_Registers.OBP0 = 0xFF;
    IO_Registers.OBP1 = 0xFF;
    IO_Registers.WY = 0;
    IO_Registers.WX = 0;
}

void IO_store_byte(uint16_t address, uint8_t data) {
    switch (address) {
        case 0xFF00:
            IO_Registers.P1 = data;
            break;
        case 0xFF01:
            IO_Registers.SB = data;
            break;
        case 0xFF02:
            IO_Registers.SC = data;
            break;
        case 0xFF04:
            IO_Registers.DIV = 0;
            break;
        case 0xFF05:
            IO_Registers.TIMA = data;
            break;
        case 0xFF06:
            IO_Registers.TMA = data;
            break;
        case 0xFF07:
            IO_Registers.TAC = data;
            break;
        case 0xFF0F:
            IO_Registers.IF = data;
            break;
        case 0xFF10:
            IO_Registers.NR10 = data;
            break;
        case 0xFF11:
            IO_Registers.NR11 = data;
            break;
        case 0xFF12:
            IO_Registers.NR12 = data;
            break;
        case 0xFF13:
            IO_Registers.NR13 = data;
            break;
        case 0xFF14:
            IO_Registers.NR14 = data;
            break;
        case 0xFF16:
            IO_Registers.NR21 = data;
            break;
        case 0xFF17:
            IO_Registers.NR22 = data;
            break;
        case 0xFF18:
            IO_Registers.NR23 = data;
            break;
        case 0xFF19:
            IO_Registers.NR24 = data;
            break;
        case 0xFF1A:
            IO_Registers.NR30 = data;
            break;
        case 0xFF1B:
            IO_Registers.NR31 = data;
            break;
        case 0xFF1C:
            IO_Registers.NR32 = data;
            break;
        case 0xFF1D:
            IO_Registers.NR33 = data;
            break;
        case 0xFF1E:
            IO_Registers.NR34 = data;
            break;
        case 0xFF20:
            IO_Registers.NR41 = data;
            break;
        case 0xFF21:
            IO_Registers.NR42 = data;
            break;
        case 0xFF22:
            IO_Registers.NR43 = data;
            break;
        case 0xFF23:
            IO_Registers.NR44 = data;
            break;
        case 0xFF24:
            IO_Registers.NR50 = data;
            break;
        case 0xFF25:
            IO_Registers.NR51 = data;
            break;
        case 0xFF26:
            IO_Registers.NR52 = data;
            break;
        case 0xFF30:
            IO_Registers.WAVE[0] = data;
            break;
        case 0xFF31:
            IO_Registers.WAVE[1] = data;
            break;
        case 0xFF32:
            IO_Registers.WAVE[2] = data;
            break;
        case 0xFF33:
            IO_Registers.WAVE[3] = data;
            break;
        case 0xFF34:
            IO_Registers.WAVE[4] = data;
            break;
        case 0xFF35:
            IO_Registers.WAVE[5] = data;
            break;
        case 0xFF36:
            IO_Registers.WAVE[6] = data;
            break;
        case 0xFF37:
            IO_Registers.WAVE[7] = data;
            break;
        case 0xFF38:
            IO_Registers.WAVE[8] = data;
            break;
        case 0xFF39:
            IO_Registers.WAVE[9] = data;
            break;
        case 0xFF3A:
            IO_Registers.WAVE[10] = data;
            break;
        case 0xFF3B:
            IO_Registers.WAVE[11] = data;
            break;
        case 0xFF3C:
            IO_Registers.WAVE[12] = data;
            break;
        case 0xFF3D:
            IO_Registers.WAVE[13] = data;
            break;
        case 0xFF3E:
            IO_Registers.WAVE[14] = data;
            break;
        case 0xFF3F:
            IO_Registers.WAVE[15] = data;
            break;
        case 0xFF40:
            IO_Registers.LCDC = data;
            break;
        case 0xFF41:
            IO_Registers.STAT = data;
            break;
        case 0xFF42:
            IO_Registers.SCY = data;
            break;
        case 0xFF43:
            IO_Registers.SCX = data;
            break;
        case 0xFF44:
            IO_Registers.LY = data;
            break;
        case 0xFF45:
            IO_Registers.LYC = data;
            break;
        case 0xFF46:
            IO_Registers.DMA = data;
            break;
        case 0xFF47:
            IO_Registers.BGP = data;
            break;
        case 0xFF48:
            IO_Registers.OBP0 = data;
            break;
        case 0xFF49:
            IO_Registers.OBP1 = data;
            break;
        case 0xFF4A:
            IO_Registers.WY = data;
            break;
        case 0xFF4B:
            IO_Registers.WX = data;
            break;
        case 0xFFFF:
            IO_Registers.IE = data;
            break;
        default:
            printf("ERROR: Tried to access an unusable IO cell (%04hhX).\n", address);
            exit(EXIT_SUCCESS);
            break;
    }
}

uint8_t IO_read_byte(uint16_t address) {
    switch (address) {
        case 0xFF00:
            return IO_Registers.P1;
            break;
        case 0xFF01:
            return IO_Registers.SB;
            break;
        case 0xFF02:
            return IO_Registers.SC;
            break;
        case 0xFF04:
            return IO_Registers.DIV;
            break;
        case 0xFF05:
            return IO_Registers.TIMA;
            break;
        case 0xFF06:
            return IO_Registers.TMA;
            break;
        case 0xFF07:
            return IO_Registers.TAC;
            break;
        case 0xFF0F:
            return IO_Registers.IF;
            break;
        case 0xFF10:
            return IO_Registers.NR10;
            break;
        case 0xFF11:
            return IO_Registers.NR11;
            break;
        case 0xFF12:
            return IO_Registers.NR12;
            break;
        case 0xFF13:
            return IO_Registers.NR13;
            break;
        case 0xFF14:
            return IO_Registers.NR14;
            break;
        case 0xFF16:
            return IO_Registers.NR21;
            break;
        case 0xFF17:
            return IO_Registers.NR22;
            break;
        case 0xFF18:
            return IO_Registers.NR23;
            break;
        case 0xFF19:
            return IO_Registers.NR24;
            break;
        case 0xFF1A:
            return IO_Registers.NR30;
            break;
        case 0xFF1B:
            return IO_Registers.NR31;
            break;
        case 0xFF1C:
            return IO_Registers.NR32;
            break;
        case 0xFF1D:
            return IO_Registers.NR33;
            break;
        case 0xFF1E:
            return IO_Registers.NR34;
            break;
        case 0xFF20:
            return IO_Registers.NR41;
            break;
        case 0xFF21:
            return IO_Registers.NR42;
            break;
        case 0xFF22:
            return IO_Registers.NR43;
            break;
        case 0xFF23:
            return IO_Registers.NR44;
            break;
        case 0xFF24:
            return IO_Registers.NR50;
            break;
        case 0xFF25:
            return IO_Registers.NR51;
            break;
        case 0xFF26:
            return IO_Registers.NR52;
            break;
        case 0xFF30:
            return IO_Registers.WAVE[0];
            break;
        case 0xFF31:
            return IO_Registers.WAVE[1];
            break;
        case 0xFF32:
            return IO_Registers.WAVE[2];
            break;
        case 0xFF33:
            return IO_Registers.WAVE[3];
            break;
        case 0xFF34:
            return IO_Registers.WAVE[4];
            break;
        case 0xFF35:
            return IO_Registers.WAVE[5];
            break;
        case 0xFF36:
            return IO_Registers.WAVE[6];
            break;
        case 0xFF37:
            return IO_Registers.WAVE[7];
            break;
        case 0xFF38:
            return IO_Registers.WAVE[8];
            break;
        case 0xFF39:
            return IO_Registers.WAVE[9];
            break;
        case 0xFF3A:
            return IO_Registers.WAVE[10];
            break;
        case 0xFF3B:
            return IO_Registers.WAVE[11];
            break;
        case 0xFF3C:
            return IO_Registers.WAVE[12];
            break;
        case 0xFF3D:
            return IO_Registers.WAVE[13];
            break;
        case 0xFF3E:
            return IO_Registers.WAVE[14];
            break;
        case 0xFF3F:
            return IO_Registers.WAVE[15];
            break;
        case 0xFF40:
            return IO_Registers.LCDC;
            break;
        case 0xFF41:
            return IO_Registers.STAT;
            break;
        case 0xFF42:
            return IO_Registers.SCY;
            break;
        case 0xFF43:
            return IO_Registers.SCX;
            break;
        case 0xFF44:
            return IO_Registers.LY;
            break;
        case 0xFF45:
            return IO_Registers.LYC;
            break;
        case 0xFF46:
            return IO_Registers.DMA;
            break;
        case 0xFF47:
            return IO_Registers.BGP;
            break;
        case 0xFF48:
            return IO_Registers.OBP0;
            break;
        case 0xFF49:
            return IO_Registers.OBP1;
            break;
        case 0xFF4A:
            return IO_Registers.WY;
            break;
        case 0xFF4B:
            return IO_Registers.WX;
            break;
        case 0xFFFF:
            return IO_Registers.IE;
            break;
        default:
            printf("ERROR: Tried to access an unusable IO cell (%04hhX).\n", address);
            exit(EXIT_SUCCESS);
            break;
    }
}