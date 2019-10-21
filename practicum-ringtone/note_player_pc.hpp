#ifndef _NOTE_PLAYER_PC_HPP
#define _NOTE_PLAYER_PC_HPP

#include "note.hpp"
#include <iostream>
#include <fstream>

// ===========================================================================
//
// abstract interface for a note player
//
// ===========================================================================

class note_player_pc {
public:
    note_player_pc()
    {
        std::ofstream outfile;
        outfile.open ("melody.cpp");
        outfile << "#include \"melody.hpp\"\n" << std::endl;
        outfile << "class fur_elise : public melody {" << std::endl;
        outfile << "public:" << std::endl;
        outfile << "   void play( note_player & p ){" << std::endl;

        outfile.close();
    }
    virtual void play(const note & n){
        std::ofstream outfile;
        outfile.open ("melody.cpp", std::ios_base::app);
        outfile << "      p.play(note{" << n.frequency << ", " << n.duration << "});" << std::endl;
        outfile.close();
    }
    void close(){
        std::ofstream outfile;
        outfile.open ("melody.cpp", std::ios_base::app);
        outfile << "   }" << std::endl;
        outfile << "};" << std::endl;
        outfile.close();
    }
};

# endif
