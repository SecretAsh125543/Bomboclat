#pragma once
#include "DrawDebugHelpers.h"

#define DRAW_DEBUG_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 50.f, 12, FColor::Purple, true);
#define DRAW_DEBUG_SPHERE_NonPerm(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 50.f, 12, FColor::Purple, false, -1.f);

#define DRAW_DEBUG_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Purple, true);
#define DRAW_DEBUG_LINE_NonPerm(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Purple, false, -1.f);

#define DRAW_DEBUG_POINT(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Purple, true);
#define DRAW_DEBUG_POINT_NonPerm(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Purple, false, -1.f);

#define DRAW_DEBUG_VECTOR(StartLocation, EndLocation) if (GetWorld()) \
{ \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Purple, true); \
	DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Purple, true); \
}
#define DRAW_DEBUG_VECTOR_NonPerm(StartLocation, EndLocation) if (GetWorld()) \
{ \
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Purple, false, -1.f); \
	DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Purple, false, -1.f); \
}
#define DRAW_DEBUG_VECTOR_1(StartLocation, EndLocation) if (GetWorld()) \
{ \
	DRAW_DEBUG_LINE(StartLocation, EndLocation); \
	DRAW_DEBUG_POINT(EndLocation); \
}