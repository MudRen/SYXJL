#include <ansi.h>
void more(string cmd, string *text, int line)
{
    int i;
    switch(cmd) {
    case "b":
        line = line - 46;
        if(line<-22) line=-23;
                write(ESC+"[1A"+ESC+"[200D"+ESC+"[K\n\n");
        for(i=line + 23; line < i;line++)
        if ( this_player()->query("env/more") && wizardp(this_player()) ) write(HIR + "[" + (line+1) + "]"+ NOR);
        write(text[line]+"\n");
        break;
    case "q":
            write(ESC+"[1A"+ESC+"[200D"+ESC+"[K\n\n");
        return;
    default:
                write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
        for(i=line + 23; line<sizeof(text) && line<i; line++) {
            if ( this_player()->query("env/more") && wizardp(this_player()) ) write(HIR+ "[" + (line+1) + "]"+ NOR);
            write(text[line] + "\n");
            }
        if( line>=sizeof(text) ) return;
        break;
    }
    printf("== 未完继续 " HIY "%d%%" NOR " == ("+HIC+"q"+NOR+" 离开，"+HIC+"b"+NOR+" 前一页，其他继续下一页)",
        (line*100/sizeof(text)) );
    input_to("more", text, line);
}
void start_more(string msg)
{
     write("\n");
    more("", explode(msg, "\n"), 0);
}

