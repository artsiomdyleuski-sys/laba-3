# Lab Assignment #3. Large-Scale OOP Project

## Domain: Social Network

### Classes

| Class | Fields | Methods | Associations (related classes) |
|---|---|---|---|
| NetworkException | 0 | 1 | — |
| InvalidUserDataException | 0 | 1 | NetworkException |
| ContentNotFoundException | 0 | 1 | NetworkException |
| AccountBannedException | 0 | 1 | NetworkException |
| ConnectionFailureException | 0 | 1 | NetworkException |
| PostNotFoundException | 0 | 1 | NetworkException |
| InvalidPostException | 0 | 1 | NetworkException |
| ModerationFailedException | 0 | 1 | NetworkException |
| SpamLimitExceededException | 0 | 1 | NetworkException |
| UserNotAvailableException | 0 | 1 | NetworkException |
| InvalidSubscriptionException | 0 | 1 | NetworkException |
| StorageLimitException | 0 | 1 | NetworkException |
| Location | 3 | 1 | — |
| TimeSlot | 3 | 1 | — |
| Filter | 3 | 1 | — |
| ModerationLog | 4 | 2 | Post |
| Metric | 3 | 2 | — |
| SpamRate | 3 | 2 | User |
| RecommendationSystem | 3 | 2 | User |
| EventLogger | 2 | 2 | — |
| Transaction | 3 | 2 | AdCampaign |
| PremiumSubscription | 4 | 2 | User |
| AdInvoice | 4 | 2 | AdCampaign |
| Advertiser | 3 | 3 | — |
| AdCampaign | 4 | 3 | Advertiser |
| NetworkBudget | 3 | 2 | Transaction |
| ContentCreator | 3 | 3 | — |
| Partnership | 4 | 2 | ContentCreator |
| ContentDelivery | 3 | 2 | MediaFile, Server |
| Server | 5 | 4 | — |
| Cache | 3 | 2 | Profile, Server |
| ServerNode | 6 | 7 | — |
| DatabaseNode | 2 | 1 | ServerNode |
| MediaNode | 2 | 1 | ServerNode |
| AuthNode | 2 | 2 | ServerNode |
| BackupNode | 2 | 2 | ServerNode |
| MediaFile | 5 | 4 | ContentCreator |
| VideoFile | 2 | 1 | MediaFile |
| ImageFile | 2 | 1 | MediaFile |
| AudioFile | 2 | 1 | MediaFile |
| Profile | 6 | 5 | MediaFile, Moderation |
| BusinessProfile | 3 | 1 | Profile |
| InfluencerProfile | 3 | 1 | Profile |
| FanProfile | 3 | 2 | Profile |
| PrivateProfile | 2 | 1 | Profile |
| VerifiedProfile | 3 | 2 | Profile |
| Moderation | 4 | 3 | Profile |
| Violation | 3 | 2 | Profile |
| ModerationReport | 3 | 2 | Violation |
| Check | 3 | 1 | — |
| SecurityCheck | 1 | 1 | Check, Profile |
| User | 6 | 5 | Group |
| Moderator | 2 | 1 | Profile |
| Admin | 2 | 1 | User |
| Tester | 2 | 2 | Post |
| SupportAgent | 1 | 1 | ServerNode |
| Recruiter | 1 | 1 | User |
| SecurityAuditor | 1 | 1 | Group |
| Group | 4 | 2 | User |
| NewsFeed | 3 | 2 | Group, Post |
| Post | 6 | 4 | Group, Profile |
| ContentPlan | 3 | 2 | Post |

### Exceptions (12)

- NetworkException
- InvalidUserDataException
- ContentNotFoundException
- AccountBannedException
- ConnectionFailureException
- PostNotFoundException
- InvalidPostException
- ModerationFailedException
- SpamLimitExceededException
- UserNotAvailableException
- InvalidSubscriptionException
- StorageLimitException

### Summary Statistics

| Metric | Value |
|---|---|
| Classes | 62 |
| Fields | ~160 |
| Behaviors | ~105 |
| Associations | ~35 |
| Exceptions | 12 |
