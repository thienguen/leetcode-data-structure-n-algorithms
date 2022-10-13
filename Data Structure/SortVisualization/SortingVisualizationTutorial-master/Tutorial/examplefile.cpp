#include "raylib.h"
#include <vector>


#define ScreenWidth 1200
#define ScreenHeight 800

#define MinWindowWidth 500
#define MinWindowHeight 800


#define FPS 120


// Piller States:
#define NORMAL 0
#define SORTED 1
#define SELECTED 2



// Size of the Array:
int NumberOfPillars = 50;


// Sorting Speed:
int SortingSpeed = 61;




// Bools:
bool ShouldRandomizeArray = true;
bool ShouldShowMenuScreen = true;
bool ShouldShowStartOptions = false;
bool ShouldStartSorting = false;
bool ShouldShowEndingScreen = false;

bool BubbleSortPressed = false;

bool addSpeed = false;
bool subSpeed = false;
bool addSize = false;
bool subSize = false;

bool NormalSize = false;
bool NormalSpeed = false;


bool MuteSound = false;


// Sorting:
void Bubble_Sort(std::vector<std::pair<int, int>> &arr);



// Screens:
void ShowMenuScreen();
void ShowStartOptions();
void ShowEndingScreen();


void Button(float x, float y, char *Text, Color color, bool &state);
void Bubble_Sort_Button(float tmp, char Bubble_Sort_text[]);
void Start_Button(float size, float font, char Start[]);


void SortArray();
void DrawArray(std::vector<std::pair<int, int>> arr);
void RandomizeArray(std::vector<std::pair<int, int>> &arr);



void ChangeSize(char operation, int &value);
void ChangeSpeed(char operation, int &value);



Color FindColorForPIller(int PillerState);


// The array itself:
std::vector<std::pair<int, int>> arr(NumberOfPillars);





int main(){

    // Window Configuration:
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(ScreenWidth, ScreenHeight, "Sorting Algorithm Visualization");
    SetWindowMinSize(MinWindowWidth, MinWindowHeight);

    InitAudioDevice();


    // Set FPS:
    SetTargetFPS(FPS);




    // Setting up sound options:
    Image SoundOnOffControl = LoadImage("Image/Sound.png");
    ImageResize(&SoundOnOffControl, 20, 20);


    Texture2D texture = LoadTextureFromImage(SoundOnOffControl);


    Sound CheelSunsetDream = LoadSound("Sound/Cheel Sunset Dream.mp3");



    while (!WindowShouldClose()){

        
        {
            float x = ((2.0 * GetScreenWidth()) / 100);
            float y = ((2.0 * GetScreenHeight()) / 100);

            Rectangle r1 = {
                .x = x,
                .y = y,
                .width = (float) x + 20,
                .height = (float) y + 20,
            };
    


            if (CheckCollisionPointRec(GetMousePosition(), r1))
                if (IsMouseButtonPressed(0))
                    MuteSound = !MuteSound;

        }




   
        
        if (MuteSound){
            DrawTexture(texture, (2*GetScreenWidth()) / 100,
                (2 * GetScreenHeight()) / 100, RED);

            PauseSound(CheelSunsetDream);
        } else {
            DrawTexture(texture, (2*GetScreenWidth()) / 100,
                (2 * GetScreenHeight()) / 100, WHITE);

            ResumeSound(CheelSunsetDream);
        }


        if (!IsSoundPlaying(CheelSunsetDream) && !MuteSound)
            PlaySound(CheelSunsetDream);





        BeginDrawing();

        ClearBackground(PURPLE);


        if (ShouldShowMenuScreen)
            ShowMenuScreen();


        
        ShouldShowStartOptions = false;
        if (BubbleSortPressed)
            ShouldShowStartOptions = true;
        


        if (ShouldShowStartOptions)
            ShowStartOptions();    



        if (ShouldRandomizeArray)
            RandomizeArray(arr);


        if (ShouldStartSorting){
            ShouldShowMenuScreen = false;
            ShouldShowStartOptions = false;


            SortArray();

            ShouldStartSorting = false;
            ShouldShowEndingScreen = true;
        }


        if (ShouldShowEndingScreen)
            ShowEndingScreen();



        EndDrawing();
    }


    UnloadImage(SoundOnOffControl);
    UnloadTexture(texture);
    UnloadSound(CheelSunsetDream); 


    CloseAudioDevice();

    CloseWindow();



    return 0;
}




// Drawing the pillers:
void DrawArray(std::vector<std::pair<int, int>> arr){
    float BarWidth = (float) GetScreenWidth() / NumberOfPillars;

    for (int i = 0; i < NumberOfPillars; i++) {
        Color color = FindColorForPIller(arr[i].second);

        DrawRectangleV (Vector2{(float) i*BarWidth, (float) GetScreenHeight() - arr[i].first},
                        Vector2{BarWidth, (float) arr[i].first},
                        color);
    }
}


// Randomizing The Array:
void RandomizeArray(std::vector<std::pair<int, int>> &arr){
    for (int i = 0; i < NumberOfPillars; i++)
        arr[i] = {GetRandomValue(40, MinWindowWidth - 80), NORMAL};


    ShouldRandomizeArray = false;

    return;
}



void ShowMenuScreen() {
    float font = (2.5 * GetScreenWidth()) / 100;
    char Bubble_Sort_Text[] = "Bubble Sort!";
    float tmp = MeasureText(Bubble_Sort_Text, font) / 2;
    Bubble_Sort_Button(tmp, Bubble_Sort_Text);


    DrawArray(arr);
}


void ShowStartOptions() {
    float font = (2.5 * GetScreenWidth() / 100);


    
    char StartText[] = "Start Sorting!";
    float tmp = (27*GetScreenWidth()) / 100;
    Start_Button(tmp, font, StartText);


    tmp += MeasureText(StartText, font) + 75;
    char RandomizeArrayText[] = "Randomize Array!";
    Button(tmp, GetScreenHeight()/20 + font*2,
        RandomizeArrayText, DARKGRAY, ShouldRandomizeArray);

    
    addSpeed = false;
    subSpeed = false;
    addSize = false;
    subSize = false;

    NormalSize = false;
    NormalSpeed = false;

    tmp = (84.2 * GetScreenWidth()) / 100;
    char TimeButtonText[] = "Speed";

 

    Button(tmp, GetScreenHeight()/20 + font*2,
        TimeButtonText, BLUE, NormalSpeed);


    if (NormalSpeed){
        ChangeSpeed('/', SortingSpeed);
        return;
    }


    tmp += MeasureText(TimeButtonText, font) + 20;
    char SpeedPlusButtonText[] = "+";
    Button(tmp, GetScreenHeight()/20 + font*2,
        SpeedPlusButtonText, ORANGE, addSpeed); 


    if (addSpeed){
        ChangeSpeed('+', SortingSpeed);
        return;
    }

    tmp += MeasureText(SpeedPlusButtonText, font) + 20;
    char SpeedMinusButtonText[] = "-";
    Button(tmp, GetScreenHeight()/20 + font*2,
        SpeedMinusButtonText, ORANGE, subSpeed);


    if (subSpeed){
        ChangeSpeed('-', SortingSpeed);
        return;
    }


    tmp = (5 * GetScreenWidth()) / 100;
    char SizeButtonText[] = "Size";
    Button(tmp, GetScreenHeight()/20 + font*2,
        SizeButtonText, BLUE, NormalSize);
    

    if (NormalSize){
        ChangeSize('/', NumberOfPillars);
        return;
    }



    tmp += MeasureText(SizeButtonText, font) + 20;
    char SizePlusButton[] = "+";
    Button(tmp, GetScreenHeight()/20 + font*2,
        SizePlusButton, ORANGE, addSize);

    if (addSize){
        ChangeSize('+', NumberOfPillars);
        return;
    }

    tmp += MeasureText(SizePlusButton, font) + 20;
    char SizeMinusButton[] = "-";
    Button(tmp, GetScreenHeight()/20 + font*2,
        SizeMinusButton, ORANGE, subSize);


    if (subSize){
        ChangeSize('-', NumberOfPillars);
        return;
    } 
}


void ShowEndingScreen(){
    DrawArray(arr);

    ShouldShowMenuScreen = true;
    ShouldShowStartOptions = false;
}



void ChangeSpeed(char operation, int &value){

    switch (operation)
    {
    case '-':
        value = value - 10 > 0 ? value - 10 : value;
        break;
    
    case '+':
        value += 10;
    
    default:
        value = 61;
        break;
    }


    SetTargetFPS(SortingSpeed);
}

void ChangeSize(char operation, int &value){
    switch (operation)
    {
        case '-':
            if (value > 5){
                value -= 5;
                for (int i = 0; i < 5; i++)
                    arr.pop_back();
            }
            break;

        case '+':
            value += 5;
            for (int i = 0; i < 5; i++)
                arr.push_back({GetRandomValue(40, MinWindowWidth-80), NORMAL});
            break;
            
    default:
        while (NumberOfPillars > 50){
            NumberOfPillars--;
            arr.pop_back();
        }

        while (NumberOfPillars < 50){
            NumberOfPillars++;
               arr.push_back({GetRandomValue(40, MinWindowWidth-80), NORMAL});
        }
        break;
    }


    for (int i = 0; i < NumberOfPillars; i++)
        arr[i].second = NORMAL;


    DrawArray(arr);
}


void Bubble_Sort_Button(float size, char Bubble_Sort_text[]){
    Color color;
    if (BubbleSortPressed)
        color = BLUE;
    else
        color = GREEN;

    
    Button(GetScreenWidth()/2 - size, GetScreenHeight()/20, Bubble_Sort_text, color, BubbleSortPressed);
}


void Start_Button(float size, float font, char Start[]){
    Button(size, GetScreenHeight()/20 + font*2,
        Start, DARKGRAY, ShouldStartSorting);

    return;
}


Color FindColorForPIller(int pillerState){
    switch (pillerState)
    {
        case SELECTED:
            return LIGHTGRAY;
            break;

        case SORTED:
            return GREEN;
            break;
        
        default:
            return GOLD;
            break;
    }
}



void SortArray(){
    Bubble_Sort(arr);

    DrawArray(arr);
}

// Bubble Sort:
void Bubble_Sort(std::vector<std::pair<int, int>> &arr) {

    int endingPoint = NumberOfPillars;


    bool swapped;
    do {
        swapped = false;

        for (int i = 0; i < endingPoint-1; i++){

            arr[i].second = SELECTED;

            if (arr[i] > arr[i+1]){

                std::swap(arr[i], arr[i+1]);


                swapped = true;
            }
       


        BeginDrawing();

        ClearBackground(PURPLE);


            for (int k = NumberOfPillars - 1; k >= endingPoint; k--)
                arr[k].second = SORTED;


            DrawArray(arr);


            for (int k = i; k >= 0; k--)
                arr[k].second = NORMAL;

            

        EndDrawing();


        }



        endingPoint--;
    } while(swapped);


    for (int i = NumberOfPillars-1; i >= 0; i--)
        arr[i].second = SORTED;
}


void Button(float x, float y, char *Text, Color color, bool &state){
    float font = (2.5 * GetScreenWidth() / 100);
    Rectangle r1 = {
        .x = x,
        .y = y,
        .width = (float) MeasureText(Text, font),
        .height = (float) font,
    };


    if (CheckCollisionPointRec(GetMousePosition(), r1)){
        DrawText(Text, x, y, font, RED);

        if (IsMouseButtonPressed(0)){

            if (state == true)
                state = false;
            else
                state = true;


            return;
        }
    } else {
        DrawText(Text, x, y, font, color);
    }


    return;
}

