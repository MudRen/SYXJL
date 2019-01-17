// report.c

#include <ansi.h>

inherit F_SAVE;

#define BOARD_CAPACITY "/clone/board/wiz_b"->query("capacity")

int do_post(string arg);

int main(object me,string arg)
{
        if( !arg || (arg!="bug" && arg!="suggest") )
                return notify_fail("ָ���ʽ��report bug|suggest\n");
        return do_post(arg);
}

string query_save_file() { return DATA_DIR + "board/wiz_b"; }

void done_post(object me, mapping note, string text)
{
        mapping *notes;
                
        note["msg"] = text;
        notes = "/clone/board/wiz_b"->query("notes");
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });

        if( sizeof(notes) > BOARD_CAPACITY )
                notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

        "/clone/board/wiz_b"->set("notes", notes);
        tell_object(me, "������ϡ�\n");

        "/clone/board/wiz_b"->save();
        return;
}

int do_post(string arg)
{
        mapping note;

        note = allocate_mapping(5);
        note["title"] = arg;
        note["author"] = this_player()->query("name");
        note["usr_id"] = this_player()->query("id");
        note["time"] = time();
        this_player()->edit( (: done_post, this_player(), note :) );
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��report bug|suggest

���ָ�����㱨�� Bug �� ������Ľ������ʦ��

HELP
        );
        return 1;
}
