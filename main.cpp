#include "LittleFS.h"

void space(int number)
{
  if(number == 0)
  {
    return;
  }
  for(int i = 0; i < number;  i++)
  {
    Serial.print("   ");
  }
}

int getNumberOfFiles(String path)
{
  int amountFilesInRoot = 0;
  Dir dir = LittleFS.openDir(path);
  while(dir.next())
  {
    amountFilesInRoot++;
  }
  return amountFilesInRoot;
}

void recursive(String path)
{
  static int insideDirs = 0;
  static String mainPath = "";
  String oldPath = mainPath;
  mainPath = path;
  Dir dir = LittleFS.openDir(path);
  int number = getNumberOfFiles(path);
  int actual = 0;
  while(actual <= number)
  {
    dir.next();
    space(insideDirs);
    if(dir.isFile())
    {
      Serial.print("|- ");
      Serial.print(dir.fileName());
      Serial.print(" -> ");
      Serial.print(dir.fileSize());
      Serial.println("Byte");
    }
    if(dir.isDirectory())
    {
      insideDirs++;
      String cPath = mainPath + "/" + dir.fileName();
      Serial.print("|--| ");
      Serial.println(dir.fileName());
      recursive(cPath);
    }
    actual++;
    if(actual >= number)
    {
      if(insideDirs > 0)
      {
        insideDirs--;
      }
    }
  }  
  mainPath = oldPath;
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Start");
  /*
  if(!LittleFS.format())
  {
    Serial.println("Error formatting Filesystem!");
  }
  else
  {
    Serial.println("Filesystem successfully formated!");
  }
  */
  LittleFS.begin();
  recursive("/");
  
}
void loop()
{
  
}
