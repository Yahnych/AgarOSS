#pragma once
#include "Protocol_13.hpp"

class Protocol_14 : public Protocol_13 {
public:
    Protocol_14(Player *owner): 
        Protocol_13(owner) {
    }
    virtual Buffer &updateLeaderboardList() {
        /*buffer.writeUInt32_LE(0x35);

        for (Player *p : map::game->leaders) {
            unsigned char flags = 0x00;

            if (false)
                flags |= 0x01; // player place
            if (true)
                flags |= 0x02; // player name
            if (p->id == player->id)
                flags |= 0x08; // is me
            buffer.writeUInt8(flags);

            if (flags & 0x01)
                buffer.writeUInt16_LE(69);
            if (flags & 0x02)
                buffer.writeStrNull_UTF8(p->cellNameUTF8());
            if (flags & 0x08)
                buffer.writeUInt8(0x08);
        }*/
        return buffer;
    }
};