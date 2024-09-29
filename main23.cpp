/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

// Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

// Tốc độ khung hình
const int FRAME_RATE = 15;

// Screen dimension constants
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
// Đường dẫn tới hình ảnh (sprites)
const int FRAME_COUNT = 4;
const int FRAME_DELAY = 100; // Thời gian giữa các khung hình (ms)

// Texture wrapper class
class LTexture
{
public:
	// Initializes variables
	LTexture();

	// Deallocates memory
	~LTexture();

	// Loads image at specified path
	bool loadFromFile(std::string path);

	// Deallocates texture
	void free();

	// Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Set blending
	void setBlendMode(SDL_BlendMode blending);

	// Set alpha modulation
	void setAlpha(Uint8 alpha);

	// Renders texture at given point
	void render(int x, int y, SDL_Rect *clip = NULL);

	// Gets image dimensions
	int getWidth();
	int getHeight();

private:
	// The actual hardware texture
	SDL_Texture *mTexture;

	// Image dimensions
	int mWidth;
	int mHeight;
};

// Starts up SDL and creates window
bool init();

// Loads media
bool loadMedia();

// Frees media and shuts down SDL
void close();

// The window we'll be rendering to
SDL_Window *gWindow = NULL;

// The window renderer
SDL_Renderer *gRenderer = NULL;

// Walking animation
const int WALKING_ANIMATION_FRAMES = 2;
SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];
SDL_Rect gtung;
LTexture gSpriteSheetTexture;
LTexture gbackground;
LTexture Road;
LTexture::LTexture()
{
	// Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	// Deallocate
	free();
}

SDL_Texture *LoadTexture(const char *file, SDL_Renderer *ren)
{
	SDL_Texture *texture = IMG_LoadTexture(ren, file);
	if (texture == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", IMG_GetError());
	}
	return texture;
}

bool LTexture::loadFromFile(std::string path)
{
	// Get rid of preexisting texture
	free();

	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			// Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	// Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	// Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
	// Modulate texture rgb
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
	// Set blending function
	SDL_SetTextureBlendMode(mTexture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
	// Modulate texture alpha
	SDL_SetTextureAlphaMod(mTexture, alpha);
}

void LTexture::render(int x, int y, SDL_Rect *clip)
{
	// Set rendering space and render to screen
	SDL_Rect renderQuad = {x, y, mWidth, mHeight};

	// Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	// Render to screen
	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

bool init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	// Loading success flag
	bool success = true;
	if (!Road.loadFromFile("road.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	if (!gbackground.loadFromFile("nenchuan.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	// Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("finalcar.png"))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{

		// Set sprite clips
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 307;
		gSpriteClips[0].h = 86;

		gSpriteClips[1].x = 0;
		gSpriteClips[1].y = 103;
		gSpriteClips[1].w = 307;
		gSpriteClips[1].h = 86;
	}

	return success;
}

void close()
{
	// Free loaded images
	gSpriteSheetTexture.free();
	gbackground.free();
	Road.free();

	// Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char *args[])
{
	// Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			SDL_Rect column;
			column.x = 1200; // Vị trí ban đầu của cột trên trục X
			column.y = 220;	// Vị trí ban đầu của cột trên trục Y
			column.w = 10;	// Chiều rộng của cột
			column.h = 200; // Chiều cao của cột
			SDL_Texture *texture = LoadTexture("road.png", gRenderer);
			// Main loop flag
			bool quit = false;

			// Event handler
			SDL_Event e;

			// Current animation frame
			int frame = 0;

			int frame2 = 0;
			Uint32 lastTime = SDL_GetTicks();
			SDL_Rect srcRect = {0, 0, 1200, 600};			 // Kích thước của từng khung hình (frame)
			SDL_Rect destRect = {0, (600 - 180), 1200, 180}; // Vị trí hiển thị trên màn hìn
			// While application is running
			while (!quit)
			{
				// Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					// User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
				Uint32 currentTime = SDL_GetTicks();
				if (currentTime > lastTime + FRAME_DELAY)
				{
					frame2 = (frame2 + 1) % FRAME_COUNT;
					srcRect.x = frame2 * 100; // Giả sử mỗi frame có chiều rộng 100px
					lastTime = currentTime;
				}
				// Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0xFF, 0xFF);

				SDL_RenderClear(gRenderer);
				
				column.x -= 50;

				// Nếu cột vượt ra khỏi màn hình, đặt lại vị trí ban đầu
				if (column.x < 0)
				{
					column.x = 1200; // Đặt lại vị trí cột phía trên màn hình
				}

				// Vẽ màn hình nền
				
				
                gbackground.render(0, 0);
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
				SDL_RenderFillRect(gRenderer, &column);

				// Hiển thị lên màn hình
				

				// Thêm một độ trễ để giới hạn tốc độ khung hình

				// Render current frame
				SDL_Rect *currentClip = &gSpriteClips[frame / 2];
                
				SDL_RenderCopy(gRenderer, texture, &srcRect, &destRect);
				gSpriteSheetTexture.render(100, 416, currentClip);

				// Update screen
				SDL_RenderPresent(gRenderer);

				// Giới hạn tốc độ khung hình
				SDL_Delay(1000 / FRAME_RATE);
				// Go to next frame
				++frame;

				// Cycle animation
				if (frame / 2 >= WALKING_ANIMATION_FRAMES)
				{
					frame = 0;
				}
			}
		}

		// Free resources and close SDL
		close();
	}

	return 0;
}
// g++ -Isrc/Include -Lsrc/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image